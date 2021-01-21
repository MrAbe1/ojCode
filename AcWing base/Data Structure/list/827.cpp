#include<iostream>
using namespace std;
const int N=10010;
int e[N],r[N],l[N],idx;
//链表的TLE看看操作又没有写错
void init(){
    // 0是左端点，1是右端点,idx从2开始
    r[0]=1;
    l[1]=0;
    idx=2;
}
// 在节点k的右边插入一个数x
void insert(int k,int x){
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k] = idx;
    idx++;
}
//删除结点k
void remove(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
int main(){
    int m;
    cin>>m;
    init();
    string  op;
    while(m--){
        int x,k;
        cin>>op;
        if(op =="L"){
            cin>>x;
            insert(0,x);
        } else if(op == "R"){
            cin>>x;
            insert(l[1],x);

        }else if(op =="D"){
            cin>>k;
            remove(k+1);
        }else if(op =="IL"){
            cin>>k>>x;
            insert(l[k+1],x);

        }else if(op =="IR"){
            cin>>k>>x;
            insert(k+1,x);
        }

    }
    for(int i=r[0];i!=1;i=r[i])
    cout<<e[i]<<' ';
    cout<<endl;
    return 0;
}