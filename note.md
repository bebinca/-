* P1177 sorting 快速排序 nlogn
  * mid=arr[(i+j)/2]
  * 中间元素mid作为key，i++找第一个大于等于mid的，j--找第一个小于等于mid的，如果i<=j则交换，继续操作直到i>j停止，对两边做quicksort
* P1309 瑞士轮
  * 赢的score+1，输的score不变，所以win和lose是两个有序数组，对其做mergesort即可，复杂度R*N
* P1908 逆序对
  * mergesort求逆序对
  * 树状数组【待更新

