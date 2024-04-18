#include "task.h"
#include <fstream>
#include <string>
#include <unordered_map>
namespace TMP {

std::stringstream Task::r_info() {
    std::stringstream ss;
    ss << "CLB: " << m_clb << ", DSP: " << m_dsp << ", BRAM: " << m_bram
       << std::endl;
    return ss;
}

std::stringstream Task::g_info() {
    std::stringstream ss;
    return ss;
}
/*****************************************************************************/
// Task
/*****************************************************************************/
Task::Task(int clb, int dsp, int bram, std::string name, int id)
    : m_clb(clb), m_dsp(dsp), m_bram(bram), m_name(name), m_id(id){};

void Task::addTaskToChild(Task::ptr tp) { m_child.push_back(tp); }
void Task::addTaskToParent(Task::ptr tp) { m_parent.push_back(tp); }

/*****************************************************************************/
// TaskSet
/*****************************************************************************/

void TaskSet::addTask(Task::ptr t) { m_ts[t->getId()] = t; }
void TaskSet::deleteTask(Task::ptr t) { m_ts.erase(t->getId()); }
void TaskSet::addTaskFromJson(const std::string filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    json task_array;
    try {
        ifs >> task_array;
    } catch (const json::parse_error &e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return;
    }
    ifs.close();
    // 创建所有的任务,并存储所有任务到map中，key是id，value是任务的指针
    // 建立任务的父子节点的映射
    if (task_array.is_array()) {
        for (const auto &task_data : task_array) {
            try {
                Task::ptr task =
                    std::make_shared<Task>(task_data["resources"]["CLB"],
                                           task_data["resources"]["DSP"],
                                           task_data["resources"]["BRAM"],
                                           task_data["name"], task_data["id"]);
                std::vector<int> child = task_data["relatioships"]["Children"];
                std::vector<int> parent = task_data["relatioships"]["Parent"];
                child_map[task->getId()] = child;
                parent_map[task->getId()] = parent;
                addTask(task);
            } catch (const std::exception &e) {
                std::cerr << "Error creating task: " << e.what() << std::endl;
            }
        }
        // 完成任务孩子节点的初始化
        for (const auto &[k, v] : child_map) {
            Task::ptr task = m_ts[k];
            for (auto c : v) {
                Task::ptr child = m_ts[c];
                task->addTaskToChild(child);
            }
        }

        // 完成任务父节点的初始化
        for (const auto &[k, v] : parent_map) {
            Task::ptr task = m_ts[k];
            for (auto p : v) {
                Task::ptr parent = m_ts[p];
                task->addTaskToParent(parent);
            }
        }
    }
    std::cout << "add success" << std::endl;
}

} // namespace TMP
