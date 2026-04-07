#include<bits/stdc++.h>
using namespace std;

int need = 0;  //需要的轨道数目 
queue< int > q[20]; //定义20条轨道，q[i]表示第i条轨道上的列车 
int x,a[1000]; //x用来读取数据，a[]用来记录列车排列顺序 

int find(int k){
	int max_id=0,idx=-1;
	
	for(int i=1;i<=need;i++){
		int now = q[i].back();  //now表示第i列的末尾列车的序号 
		if( k > now && now > max_id) {//查找每一列最后一位的序号，这个序号要小于新加入的列车，且要是最大的一个 
			max_id = now;
			idx = i;
		}
	}
	
	return idx;  //若没找到则是默认值-1 
}


int main(){
	//数据输入部分，n表示输入的总列车数， 
	int n=0;
	while(cin>>x){
		a[n++] = x;
	}
	
	for(int i=n-1;i>=0;i--){ // 对每辆列车选择最优队列，由于题目要求从后往前排列，英雌i从n-1到0 
		int idx = find(a[i]);   //idx表示第i辆列车排在第idx位的轨道，若idx=-1则需要新建轨道 
		
		if(idx == -1){
			need++;
			q[need].push(a[i]);   //将i号列车放到新建的第need号轨道 
		}
		else{
			q[idx].push(a[i]);   //将i号列车放到确定的idx轨道且不新建 
		}
	} 
	
	cout<<need;
	return 0;
} 
