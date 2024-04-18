#pragma once
#include "singleton.h"
#include "util/nlohmann/json.hpp"
#include "util/nlohmann/json_fwd.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using json = nlohmann::json;
namespace TMP {
// Task
// 存放任务的相关信息及其父,子节点
class Task : std::enable_shared_from_this<Task> {
  public:
    using ptr = std::shared_ptr<Task>;
    Task(int clb, int dsp, int bram, std::string name, int id);
    int getClb() const { return m_clb; }
    int getDsp() const { return m_dsp; }
    int getBram() const { return m_bram; }
    int getId() const { return m_id; }
    int getRt() const { return m_runtime; }
    std::string getName() const { return m_name; }
    std::vector<Task::ptr> getChild() const { return m_child; };
    std::vector<Task::ptr> getParent() const { return m_parent; };
    std::stringstream r_info();
    std::stringstream g_info();
    void addTaskToChild(Task::ptr tp);
    void addTaskToParent(Task::ptr tp);
    json TaskToJson();

  private:
    const std::string m_name;
    const int m_id;
    const int m_clb;
    const int m_dsp;
    const int m_bram;
    int m_runtime;
    bool is_single = true;
    std::vector<Task::ptr> m_child = {};
    std::vector<Task::ptr> m_parent = {};
};
// 任务集合
// 从Json文件创建任务集合
class TaskSet {
    friend class Task;

  public:
    using ptr = std::shared_ptr<TaskSet>;
    TaskSet(){};
    std::unordered_set<Task::ptr> getTS();
    void addTask(Task::ptr t);
    void deleteTask(Task::ptr t);
    void addTaskFromJson(const std::string filename);
    Task::ptr JsonToTask(json j);
    void TsInfo();

  private:
    std::unordered_map<int, Task::ptr> m_ts; // 存放所有的Task key是id
    std::unordered_map<int, std::vector<int>> child_map;
    std::unordered_map<int, std::vector<int>> parent_map;
};

} // namespace TMP
