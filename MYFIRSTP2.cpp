#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
int A[3][3]={1,2,3,4,5,6,7,8,9};
int show()
{
   for(int i=0;i<3;i++)
   {
     cout<<"\n\n";
    for(int j=0;j<3;j++)
    {
    cout<<"\t"<<A[i][j]<<"\t";
    }

   }
}
int enter1()
{
int choice1;
cout<<"\n enter number to choose Player1[0]:=";
cin>>choice1;
for(int i=0;i<3;i++)
{
  for(int j=0;j<3;j++)
   {
    if(choice1==A[i][j])
     {
      A[i][j]=0;
     }
}
}
}
int enter2()
{
int choice2;
cout<<"\n enter number to choose Player2[10]:=";
cin>>choice2;
for(int i=0;i<3;i++)
{
  for(int j=0;j<3;j++)
   {
    if(choice2==A[i][j])
     {
      A[i][j]=10;
     }
    }
}
}
int check(int x)
{
   int j,k,c=0,f=0,e=0,m,n,p=0,q=0,r=0,s=0,t=0;
   for(j=0;j<3;j++)
  {
	if(A[0][j]!=x)
	 { c++; }
     if(A[1][j]!=x)
	{ p++; }
     if(A[2][j]!=x)
       { q++; }
     if(A[j][0]!=x)
       { r++; }
   if(A[j][1]!=x)
      { s++; }
   if(A[j][2]!=x)
     { t++; }
  }


for(m=0;m<3;m++)
{
  if(A[m][m]!=x)
   {
    e++;
   }
}
for(m=0,n=2;m<3;m++,n--)
{
   if(A[m][n]!=x)
   {
    f++;
   }
}
if(c==0||e==0||f==0||r==0||p==0||t==0||s==0||q==0)
{
  if(x==0)
   {
    cout<<"\n Player1 wins";
    getch();
     exit(0);
    }
   if(x==10)
    {
     cout<<"\n Player 2 wins";
     getch();
     exit(0);
    }
}
}



int main()
{

for(int z=0;z<10;z++)
{
show();
enter1();
show();
check(0);
enter2();
check(10);

}
return 0;
getch();
}
