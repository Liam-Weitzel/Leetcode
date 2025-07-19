#include <map>
#include <string>
#include <vector>

struct dir {
  std::string name;
  std::map<std::string, dir> subdirs;
  bool input = false;
};

class Solution {
public:
  std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
    dir root;

    for (const std::string& path : folder) {
      std::vector<std::string> dirSplit;
      size_t curIndex = 1;
      size_t curIter = path.find('/', 1);

      while (curIter != std::string::npos) {
        dirSplit.push_back(path.substr(curIndex, curIter - curIndex));
        curIndex = curIter + 1;
        curIter = path.find('/', curIndex);
      }

      if (curIndex < path.length()) {
        dirSplit.push_back(path.substr(curIndex));
      }

      dir* current = &root;
      bool skip = false;
      for (int i = 0; i < dirSplit.size(); ++i) {
        if (current->input) {
          skip = true;
          break;
        }
        current = &current->subdirs[dirSplit[i]];
      }

      if (!skip) {
        current->input = true;
      }
    }

    std::vector<std::string> result;
    dfs(&root, "", result);
    return result;
  }

private:
  void dfs(dir* node, std::string path, std::vector<std::string>& result) {
    for (auto& [name, child] : node->subdirs) {
      std::string currentPath = path + "/" + name;
      if (child.input) {
        result.push_back(currentPath);
      } else {
        dfs(&child, currentPath, result);
      }
    }
  }
};
