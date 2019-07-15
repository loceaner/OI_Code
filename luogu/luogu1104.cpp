#include<iostream>
#include<algorithm>
using namespace std;
struct mate
{
    char name[20];
    int year;
    int month;
    int day;
    int num;
}
stu[101];
bool comp(mate a,mate b)
{
    if(a.year!=b.year)
        return a.year<b.year;
    else if(a.month!=b.month)return a.month<b.month;
    else if(a.day==b.day&&a.month==b.month)return a.num>b.num;
    else if(a.day!=b.day&&a.month==b.month)return a.day<b.day;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>stu[i].name>>stu[i].year>>stu[i].month>>stu[i].day;
        stu[i].num=i;
    }
    sort(stu+1,stu+1+n,comp);
    for(int i=1;i<=n;i++)
    {
        cout<<stu[i].name<<endl;
    }
    return 0;
}
