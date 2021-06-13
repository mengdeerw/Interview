第一轮： 国人小姐姐，给两个int val和一棵二叉树，要求返回这个nodes之间的path，path是str且用up，left，right表示。因为是一大早第一轮 有点紧张，脑子还有点懵，所以第一反应是先找第一个node，拿stack存parent，再找第二个node。我这做法应该是bfs的做法但我却写成了dfs，可想而知卡住了。好在小姐姐提醒可以先分别找root 到node1，root到node2的path。她一提醒就马上发现拿到这两个paths后可以cut prefix然后reverse 其中一个path再合并就是答案。最后 dfs写完，口头跑了test case，string 操作因为时间不够小姐姐让写了Pseudocode。希望小姐姐手下留情，能给过。大家以后面试还是要先多思考，别上来就写。
第二轮bq：一国人老哥，人很好，聊的不错就不细说了。
第三轮：继续国人老哥，上来拿出女儿的游戏棋盘，描述了一番，听上去很复杂，实际就是掷色子走棋子，问你最少掷几次色子能到终点。注意棋盘中还有特殊的格子，一种是梯子能让你往前n格，一种是水流让你倒退n格。简化到最后实际上就是一维dp。秒了。
第四轮：三哥，原题幺幺幺灵。秒了，follow up为啥dfs不是bfs，假如数据量很大怎么scale
第五轮：白人大叔，给你一堆餐厅菜品的配方，有些菜品可能要用到别的菜品作为原料，比如面包需要面粉鸡蛋，另一道菜可能需要面包作为成分。假如给你一个现有原料的list（原料无限供应），问你能做哪几道菜作为今天的菜单。实际上就是加壳的拓扑排序，也秒了

亚裔小姐姐！友善健谈 让我紧张的心态得到了缓解
1.问题是一道比较real time的题 有一个class of developer， class of ticket， 每一个developer 都有tag list， ticket也有taglist
method1 给一个ticket找到所有的有任一tag的developer list
method2 给一个ticket找到match所有tag的developer list
2.BQ 面， 怎么样处理multitask， 怎么样跟经理说完成不了任务，以及给一个sample你超过预期的完成任务
3.印度小姐姐， 问题是找不同 给两个string “abc” -> "ab"  output -> c   ; "ac" -> "acb" => b; "abccd" and "abddd" => "cc" and "dd“
4.白人大哥。。。应该挂在这里 give a sorted array find the duplicate of a given number
5.中国大哥 leetcode 巴斯林 变种

4轮面的coding 都不是常规的算法题，更偏向data structure。
1. bq question，conflict，怎么提高diveristy
2. 给一大堆车和路口的logs，计算出每个车应该交的钱，聊structure 聊了特别长的时间+聊如果billions of logs 怎么处理
3. 定义rectangle，定义矩形怎么重合，如果输入一大堆的矩形，输出所有的pairs of 重合矩形，followup 如果输入有billions of 矩形 怎么办
4. 聊hashmap 题目我不记得了，最后问我怎么让一个tree balance， 一个东北小姐姐，虽然很可爱，但是她的英语我听不太懂，所有的单词都加了儿化音。。。。。
5. 也是输入一堆logs，每个log 包括了rpc 的id 和start time/end time，问我如何最短时间找出timeout

4 coding + 1 BQ.
Round 1: 刷题网贰柒叁. 问了些细节，比如为什么直接从billion开始, 因为给的code写了input是int
Round 2: 应该不是刷题网的题. 面试官的问题大概是要求去diff两个Json input.
比如{a: 1, b: 2, c : 5} 和{a, {d: 1}, b: 2}..可以自定义数据类型.
我的做法是直接flattern json, 然后形成两个Map<String, JsonValue> prev, Map<String, JsonValue> next. 问题就变成了diff两个Map. Map的key是json key path.
这轮和面试官感觉沟通有点迷. 我先写的Map diff, 然后他要我go through下，我就找了个例子试了下，然后他忽然意识到我已经定义好的flatternJson还没写...然后我就写了.
flatternJson每一个key代表了到每一个jsonvalue的path, 类似"key1 - key2 - keyn"这样的序列化.
感觉这轮因为需要自定义的东西有点多. 关于如何去output diff感觉面试官自己也不知道...怎么diff其实包含了update, delete, new这三种cases. 其实如果定义明确的话，甚至不需要flattern, 类似于两个tree compare, 应该是可以dfs的.
Round 3: 貌似也不是刷题网的题. 问题是给一个File rawtext, 里面有各种raw text, 再给一个禁词字典file.
要求把所有在rawtext里出现的禁词都隐藏掉(可以认为是换成星号).
明确如何定义词, 讨论完明确了比如出现space, dot, nextline就不算word了.
一开始我说忘了file读的api了，于是一开始实现是按照整个file当作string读进去来实现的.
follow up: 如果rawtext file特别大怎么办? 没法整个放内存里. 读文件，stream每次2个bytes.
follow up: 如果禁词字典很大怎么办？拆分字典，然后一个个对rawtext进去过滤.
follow up: 这种实现是sequential的，如果想快点怎么办？上分布式，拆了字典然后多机过滤，完了再merge.
Round 4:
迷宫生成器. 给定一个迷宫的长，宽，起点，终点. 生成一个迷宫. 迷宫定义: 起点一定能走到终点.
dfs找出一条路径，记录路径所有点，对迷宫2d array上在路径上的点都标记为valird, 其他所有点用random的方式标记为valid / invalid.
follow up: 如何使得这条路径本身看起来'随机'一点. 修改dfs next direction的顺序，采用随机的方式生成[0-3](对应上下左右)的下一个方向, 直到四个方向的dfs都visited.(bitmask 4个bits).
round 5: BQ.


1.
设计一个优惠券系统， 实现下面三个借口
Void addOffer(int productId, int offerId, double price);
Void removeOffer(int offerId);
Int getOfferIdWithClosestPrice(int price);
followUp: 多线程

2.leetcode-1548
应该是个图论题，只给出了backtrack暴力解。 求大神解答
给一个路径, 每一个string是一个城市的名字。 ex: aaa, bbb, ccc。 但是每一个城市的名字不一定是对的。
给三个函数:
ImmutableSet<String> getAllCityName();         // return all the correct city name
ImmutableList<String> getNeighbors(String city)        // return the neighbors given a correct city name
int nameDist (String city1, String city2)        // return the replacement diff between 2 strings, ex: nameDist("bbb", "bxb") = 1;
如果一个路径，每一对相邻的城市都是neighbor，并且所有的城市名字都是对的，这个路径为合法路径。
要求写一个函数return一个合法路径，使得这个路径和给定的路径总的nameDist最短。

3.二叉树
Node {
String val;
Node left;
Node right;
Int num_children;
}
求在排序后的第n个Node。 这道题一直没想到，最后才做出来。
followup没时间做了

4. 两个file，一个file是text，另一个file是words。 要把第二个file里的单词从第一个file里去掉。
Corner case比较多，以为做对了，结果后来发现我把标点符号也去了。
followup: 多线程， 分布式怎么弄
  
1.第一轮 三哥 幺儿零九 变种， 要求k>=3 我一上来用的是stack解法
2.第二轮 看似三哥  最接近 幺儿无私  求最大岛屿面积。 这里的岛屿包括四面环水，以及closed island：边缘水域不能算有效面积，但是大陆围上的水域需要算上。上例子：
0 1 0 0
0 1 0 0
1 1 0 1
result: 4

0 1 1  1
0 1 0  1
0 1 1  1
result: 9
我写了两个dfs， 一个是从边缘把水的区域全部Mark上，在用另外一个dfs算有效面积
follow up： 岛屿面积的总和

3.第三轮： 二要领 变种， 给一堆pair 表示字母排序的顺序 ['y', 'x'] 表示y出现在x前面，输出 有效的顺序串。
4.第四轮： 一个很长很长很长的题目，基本就是copy过来的，读了五分钟题。就是给一堆三元组（x, y, t）表示x向y在t的时间传递消息。问最后所有知道消息的entity。
follow-up: 如果在t的时刻，会有多个pair在传递消息。
5.第五轮： 常规bq, 白人小哥 一上来就说这一轮是你所有面试的最简单的一轮。聊了二十分钟。小哥没啥问题了。


