# **leetcode-Weekly-competition**
## **力扣周赛**
### **特别感谢哔哩哔哩up主：喂你脚下有坑**
**我的不会的题目以及会的题目的改进基本都来自这位up的讲解视频**
## 第167周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-167/
## 第168周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-168/
## 第170周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-170/
## 第171周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-171/
## 第172周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-172/
## 第173周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-173/
## 第174周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-174/
## 第175周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-175/
## 第176周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-176/
## 第177周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-177/
## 第178周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-178/
## 第179周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-179/
## 第180周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-180/
## 第181周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-181/
## 第183周周赛
题目🔗：https://leetcode-cn.com/contest/weekly-contest-181/

## 第19 双周赛
题目🔗：https://leetcode-cn.com/contest/biweekly-contest-19/
## 第20 双周赛
题目🔗：https://leetcode-cn.com/contest/biweekly-contest-20/
## 第21 双周赛
题目🔗：https://leetcode-cn.com/contest/biweekly-contest-21/
## 第22 双周赛
题目🔗：https://leetcode-cn.com/contest/biweekly-contest-22/

## 最近毕设的事情有点忙，182周鸽了/滑稽
### **有时间把之前这些周的题目中的tips也总结过来**

### **DFS模板(有空刷完算法ABC的深搜模块)**
### **无论是BFS还是DFS都要维护一个Visited[]来判断当前状态是否已经访问过了，一定是确实到达了这个点才对visited数组进行更新(对于二叉树不需要)**
```c++
void dfs()//参数用来表示状态  
{  
    if(到达终点状态)  
    {  
        ...//根据题意添加  
        return;  
    }  
    if(越界或者是不合法状态)  
        return;  
    if(特殊状态)//剪枝
        return ;
    for(扩展方式)  
    {  
        if(扩展方式所达到状态合法)  
        {  
            修改操作;//根据题意来添加  
            标记；  
            dfs（）；  
            (还原标记)；  
            //是否还原标记根据题意  
            //如果加上（还原标记）就是 回溯法  
        }  
 
    }  
}  
```

### 二维Vector 初始化
- vector< vector<int>> tmp(10,      vector<int>(10,0));

### 二叉树层次遍历并记录每一层的结点数的方法： BFS的同时用 count记录当前层的节点总数， newState记录下一层的节点总数， cur记录当前遍历到哪个节点
```c++
while(!Q.empty()){
    TreeNode* tmp = Q.front(); Q.pop();
    tt.push_back(tmp->val);
    if(tmp->left != NULL) Q.push(tmp->left), nextCount++;
    if(tmp->right != NULL) Q.push(tmp->right), nextCount++;
    cur++;
    if(cur == Count){
        buf.push_back(tt);
        tt.clear();
        cur = 0;
        Count = nextCount;
        nextCount = 0;
    }
}
```
### 只要看到地图优先想bfs or dfs 再想 迪杰斯特拉 SPFA　再想ＤＰ

### scanf 从控制台输入 fscanf 从文件输入 sscanf 从指定字符串输入
### 日期类题目：
- sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day); 格式化读取年月日
- scanf 从控制台输入 fscanf 从文件输入 sscanf 从指定字符串输入
- #define is_year(x) (x % 400 == 0) || (x % 4 ==0 && x % 100 !=0) ? 1 : 0
```c++
sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int month_length[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int ans = 0;
        while (year != 1971 or month != 1 or day != 1) {
            ++ans;
            if (--day == 0)
                if (--month == 0)
                    --year;
            if (day == 0) {
                day = month_length[month];
                if (month == 2 && leap_year(year))
                    ++day;
            }
            if (month == 0)
                month = 12;
        }
```

### // tips：当要求有限个字母或数字的有限个状态时，要记得联想到状态压缩技巧 // tips: 字符串灵活使用前缀和
### cnt[26]统计字母频次的专用数组！！！

### string.substr(0, n) 取字串
### 如果是子串拼接成原串问题，那么就把两个原串拼在一起(str1 + str2 | str2 + str1)，子串能拼出两个原串拼接在一起的话就能拼出两个原串（if (str1+str2!=str2+str1) return "";）

### 摩尔投票法求众数

### tips: 二维vector sort排序 
```c++
//{{1,2,3},{1,2,4},{1,2,5},{1,2,6},{1,2,7},{1,2,8}} 会按照每一行的第一个值排序，第一个值相同再比较第二个值，和vector<pair<>>的道理是一样的
//vector 从大到小排序 sort(tmp.begin(), tmp.end(), greater<vector<int>>()) || sort(tmp.rbegin(),tmp.rend())
// 乘方函数 pow（x,y) x^y
```

### 如果答案的计算公式 =  A * min(B)，那我们不妨枚举B的中的所有值，另一项得到最优解，那么就很有可能找到我们需要的值