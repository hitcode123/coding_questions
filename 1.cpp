#include<iostream>
#include<vector>

using namespace std;
class DisJoint{

private:
vector<int> rank,upar;

public:
DisJoint(int n){
  rank.resize(n+1,1);
  upar.reserve(n+1);
  for(int i=0;i<=n;i++)
  {
    upar[i]=i;
  }
};

int FindUPar(int n)
{
   if(upar[n]==n)
   {
    return n;
   }
   return upar[n]=FindUPar(upar[n]);
}

void unionbyRank(int u,int v)
{
  int pu=FindUPar(u);
  int pv=FindUPar(v);
   if(pu==pv)
  {
      return ;
  }
  if(rank[pu]<rank[pv])
  {
    upar[pu]=pv;

  }
  else if(rank[pu]>rank[pu])
  {
    upar[pu]=pu;
  }
  else
  {
    upar[pu]=pv;
    rank[pv]++;
  }
  
}



};
int main()
{
   
   DisJoint j=DisJoint(6);
   j.unionbyRank(1,5);
   j.unionbyRank(2,3);
   j.unionbyRank(2,4);

   if(j.FindUPar(1)==j.FindUPar(2))
   {
    cout<<"same"<<endl;
   }
   else
   {
    cout<<"not same"<<endl;
   }
   if(j.FindUPar(1)==j.FindUPar(2))
   {
    cout<<"same"<<endl;
   }
   else{
    cout<<"not same"<<endl;
   }
   j.unionbyRank(4,5);


}