# algorithm
《计算机算法基础》书中练习 主要为python实现<br>

##一、递归法
哪些问题可以用递归求解。如果同时满足以下3个要求:
* 问题P的描述涉及规模, 即P(size);
* 规模发生变化后, 问题的性质不发生变化;
* 问题的解决有出口。

小实例：<br>
1. [最大值：](./recursion/maxnum)求n个元素中的最在大值。<br>
2. [汉诺塔：](./recursion/hanoi)汉诺塔问题。<br>
3. [全排列：](./recursion/range)求n个元素的全排列。<br>
4. [自然数拆分：](./recursion/splitnumber)任何一个大于1 的自然数n , 总可以拆分成若干
个小于n的自然数之和,试求n的所有拆分(用不完全归纳法)。<br>
5. [简单的0/1背包问题:](./recursion/simpleknap)设一背包可容物品的最大质量为m,现有n件
物品, 质量为m1 , m2 , ⋯ , mn,mi,均为正整数,要从n件物品中挑选若干件,使放入背包的质量之和正好为m。<br>

##二、分治法
求解的思想就是将整个问题分成若干个小问题后分而治之。通常, 由分治法所得到的子问题与原问题具有相同的类型。<br>
小实例:<br>
1. [二分查找](./division/binarysearch)<br>
2. [归并排序：](./division/mergesort)给定一个含有n个元素的集合,把它们按一定的次序分类
(按非降次序分类)<br>
3. [快速排序](./division/quicksort) 

##三、贪心法
所谓贪心算法是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，他所做出的仅是在某种意义上的局部最优解
。<br>
贪心策略适用的前提是：局部最优策略能导致产生全局最优解。<br>
小实例:<br>
1. [带有限期的作业排序：](./greedy/jobsort)来解决操作系统中单机、无资源约束且每个作业
可在等量的时间内完成的作业调度问题。<br>
2. [背包问题：](./greedy/knapsack)采用装包方法使装入背包物品的总效益最大。<br>
3. [Dijkstra python:](./greedy/dijkstra) or [Dijkstra c++:](./cxximpl/Dijkstra)求解单源点最短路径问题<br>
4. [最小生成树：](./greedy/spanningtree)<br>
	* [Prim python](./greedy/spanningtree/prim) or [Prim c++](./cxximpl/Prim)<br>
	* [Kruskal python](./greedy/spanningtree/kruskal) or [Kruskal c++](./cxximpl/Kruskal)<br>
5. [哈夫曼编码](./cxximpl/Huffman)<br>
6. [会议安排](./cxximpl/ArrangeConfer)

##四、动态规划
活动过程可以分为若干个阶段, 而且在任一阶段后的行为都仅依赖于i 阶段的过程状态, 而与i 阶段之前的过程如何达到这种状态的方式无关, 这样的过程就
构成一个多阶段决策过程<br>
小实例：<br>
1. 多段图:<br>
	* [向前处理法](./dynamicprogramming/fgraph)<br>
	* [向后处理法](./dynamicprogramming/bgraph)<br>
2. [Floyd：](./dynamicprogramming/floyd)每对结点之间的最短路径。<br>
3. [最优成本二分检索树：](./dynamicprogramming/optimalbinarysearchtree)详细说明见[印象笔记
](https://app.yinxiang.com/shard/s66/nl/14320022/b8c14f2d-ba6e-4415-acfe-9152f8b38621?title=%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92_%E6%9C%80
%E4%BC%98%E4%BA%8C%E5%88%86%E6%A3%80%E7%B4%A2%E6%A0%91)
