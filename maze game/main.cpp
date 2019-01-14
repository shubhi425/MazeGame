
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#define m 8
#define n 8
using namespace std;
class queue_link
{
    public:
    struct node
    {
        int row,col;
        node *link;
    }*start,*start1;

    queue_link()
    {
        start=NULL;
        start1=NULL;
    }

void insert_stack(int x,int y)
{
    node *n1=new node;
            n1->row=x;
            n1->col=y;
        if(start1==NULL)
        {
            start1=n1;
            n1->link=NULL;
        }
        else
        {
         n1->link=start1;
         start1=n1;
        }
}

void delete_stack()
{
   node *t1=start1;
   start1=start1->link;
   t1->link=NULL;
   delete(t1);

}



void insert_queue(int x,int y)
    {
        node *n1=new node;
        if(start==NULL)
        {
            n1->row=x;
            n1->col=y;
            n1->link=NULL;
            start=n1;
        }
        else
        {
         node *temp;
         temp=start;
         while(temp->link!=NULL)
         {
             temp=temp->link;
         }
         n1->row=x;
         n1->col=y;
         n1->link=NULL;
         temp->link=n1;
        }
    }

int stack_size()
{
    node *ptr=start1;
    int c=0;
    while(ptr!=NULL)
    {
         c++;
        ptr=ptr->link;
    }
    cout<<c;
    return c;

}

struct node* chances(char sol1[m][n],int flag[m][n])
{
    int sizes=stack_size();
    if(sizes<=5)
    {
        while(start1->link!=NULL)
        {
            sol1[start1->row][start1->col]=' ';
            flag[start1->row][start1->col]=0;
            delete_stack();
        }
    }
    else
    {
        int len=sizes-5;
        while(sizes!=len)
        {
            sol1[start1->row][start1->col]=' ';
            flag[start1->row][start1->col]=0;
            delete_stack();
            sizes -=1;
        }
    }

}

bool check(int row,int col)
{
    if(row>=1 && row<m-1 && col>=1 && col<n-1)
    {
        return 1;
    }
    else return 0;
}

void delete_beg()
 {
     node *temp;
     temp=start;
     start=start->link;
     delete(temp);
 }

void display(char arr[m][n])
 {int i,j;

      for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
 }

bool right(int row,int col,char arr[m][n],char sol[m][n])
{
    if(check(row,col) && arr[row][col]!='|' && sol[row][col]!='*' && sol[row][col]!='$')
    {
        return 1;
    }
    return 0;
}


bool left(int row,int col,char arr[m][n],char sol[m][n])
{
    if(check(row,col) && arr[row][col]!='|' && sol[row][col]!='*' && sol[row][col]!='$')
    {

        return 1;
    }
    return 0;
}

bool up(int row,int col,char arr[m][n],char sol[m][n])
{
    if(check(row,col) && arr[row][col]!='|' && sol[row][col]!='*' && sol[row][col]!='$')
    {

        return 1;
    }
    return 0;
}

bool down(int row,int col,char arr[m][n],char sol[m][n])
{
    if(check(row,col) && arr[row][col]!='|' && sol[row][col]!='*' && sol[row][col]!='$')
    {

        return 1;
    }
    return 0;
}

char maze(char arr[m][n],char sol[m][n],int sr,int sc,int dr,int dc,int stage)
 {

    if (stage == 1)
    {
     int i,j,f=0;
     i=sr;j=sc;
     insert_queue(sr,sc);
     node *ptr=start;
     sol[ptr->row][ptr->col]='*';
      if(ptr->row==dr && ptr->col==dc)
      {
          cout<<"found : start = destination"<<endl;
      }
      else
      {

        while(start!=NULL)
     {
        i=start->row;
        j=start->col;
         sol[i][j]='*';
        if(i==dr && j==dc)
      {
          f=1;
          break;
      }
       delete_beg();
      if(right(i,j+1,arr,sol))
      {
        sol[i][j+1]='$';
        insert_queue(i,j+1);

      }
       if(left(i,j-1,arr,sol))
      {
           sol[i][j-1]='$';
        insert_queue(i,j-1);
      }
       if(up(i-1,j,arr,sol))
      {
         sol[i-1][j]='$';
        insert_queue(i-1,j);
      }
        if(down(i+1,j,arr,sol))
      {
        sol[i+1][j]='$';
        insert_queue(i+1,j);
      }

     }
      }

      if(f==1)
      {
      cout<<"found path"<<endl;
      display(sol);
      }
      else{cout<<"no path"<<endl;}
    }
 }

 char maze_game(char sol[m][n],char sol1[m][n],int sr,int sc,int dr,int dc,int stage)
{
    char option;
    cout<<"enter option :"<<endl;
    cin>>option;
    int points=0,f=0,f1=0,chance=3;
    sol1[sr][sc]='*';
    int flag[m][n]={0};
    insert_stack(sr,sc);
    flag[sr][sc]=1;
while(option != 'q')
    {
if(option=='w')
    {
        sr--;
  if(stage==1)
    {
      if(sr==dr && sc==dc)
      {sol1[dr][dc]='*';
      points +=1;
          f=1;
      }

else if(flag[sr][sc]==1)
 {
     sr++;
     cout<<"wrong way"<<endl;
 }

else if(sol[sr][sc]=='*' || sol[sr][sc]=='$')
      {          sol1[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(sol[sr][sc]=='|' || sol[sr][sc]==' ' || sol[sr][sc]=='!' || sol[sr][sc]=='-')
      {
 chances(sol1,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }
    }
    }

else if(option=='s')
    {
        sr++;
      if(stage==1)
    {
      if(sr==dr && sc==dc)
      {sol1[dr][dc]='*';
      points +=1;
          f=1;
      }

else if(flag[sr][sc]==1)
 {
     sr--;
     cout<<"wrong way"<<endl;
 }

else if(sol[sr][sc]=='*' || sol[sr][sc]=='$')
      {          sol1[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(sol[sr][sc]=='|' || sol[sr][sc]==' ' || sol[sr][sc]=='!' || sol[sr][sc]=='-')
      {
 chances(sol1,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }
    }
    }

else if(option=='a')
    {
        sc--;
     if(stage==1)
    {
      if(sr==dr && sc==dc)
      {sol1[dr][dc]='*';
      points +=1;
          f=1;
      }

else if(flag[sr][sc]==1)
 {
     sc++;
     cout<<"wrong way"<<endl;
 }

else if(sol[sr][sc]=='*' || sol[sr][sc]=='$')
      {          sol1[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(sol[sr][sc]=='|' || sol[sr][sc]==' ' || sol[sr][sc]=='!' || sol[sr][sc]=='-')
      {
 chances(sol1,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }
    }
    }
else if(option=='d')
    {
        sc++;
       if(stage==1)
    {
      if(sr==dr && sc==dc)
      {sol1[dr][dc]='*';
      points +=1;
          f=1;
      }

else if(flag[sr][sc]==1)
 {
     sc--;
     cout<<"wrong way"<<endl;
 }

else if(sol[sr][sc]=='*' || sol[sr][sc]=='$')
      {          sol1[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(sol[sr][sc]=='|' || sol[sr][sc]==' ' || sol[sr][sc]=='!' || sol[sr][sc]=='-')
      {
 chances(sol1,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }
    }

    }

    cout<<endl;
    system("cls");
 cout<<"            #MAZE GAME#            "<<endl;
    if(f==1)
    {display(sol1);cout<<"points :"<<points<<endl<<"Congratulations"<<endl;break;}
    else if(f1==1){cout<<"points:"<<points<<endl<<"Game Over"<<endl;break;}
    else {cout<<"points :"<<points<<"                      lives left :"<<chance<<endl;display(sol1);}
    cout<<endl;
    cout<<"enter option or q to quit :"<<endl;
    cin>>option;

    }
}



};



int main()
{
    int i,j,sr,sc,dr,dc,stage=1;
    queue_link q1;
    char arr[m][n],sol[m][n],sol1[m][n];
arr[0][0]=' -';arr[0][1]='-';arr[0][2]='-';arr[0][3]='-';arr[0][4]='-';arr[0][5]='-';arr[0][6]='-';arr[0][7]='-';
arr[1][0]='!';arr[1][1]='|';arr[1][2]='|';arr[1][3]='|';arr[1][4]=' ';arr[1][5]=' ';arr[1][6]=' ';arr[1][7]='!';
arr[2][0]='!';arr[2][1]=' ';arr[2][2]='|';arr[2][3]=' ';arr[2][4]=' ';arr[2][5]=' ';arr[2][6]=' ';arr[2][7]='!';
arr[3][0]='!';arr[3][1]=' ';arr[3][2]='|';arr[3][3]=' ';arr[3][4]='|';arr[3][5]='|';arr[3][6]=' ';arr[3][7]='!';
arr[4][0]='!';arr[4][1]=' ';arr[4][2]=' ';arr[4][3]=' ';arr[4][4]=' ';arr[4][5]=' ';arr[4][6]=' ';arr[4][7]='!';
arr[5][0]='!';arr[5][1]='|';arr[5][2]='|';arr[5][3]='|';arr[5][4]='|';arr[5][5]=' ';arr[5][6]=' ';arr[5][7]='!';
arr[6][0]='!';arr[6][1]=' ';arr[6][2]=' ';arr[6][3]='|';arr[6][4]=' ';arr[6][5]=' ';arr[6][6]=' ';arr[6][7]='!';
arr[7][0]='-';arr[7][1]='-';arr[7][2]='-';arr[7][3]='-';arr[7][4]='-';arr[7][5]='-';arr[7][6]='-';arr[7][7]='-';
q1.display(arr);
cout<<"enter source :"<<endl;
cin>>sr>>sc;
cout<<"enter destination :"<<endl;
cin>>dr>>dc;
cout<<endl;
for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           sol[i][j]=arr[i][j];
           sol1[i][j]=arr[i][j];
        }

    }
    //q1.display(arr);
    cout<<"stage 1"<<endl;
    q1.maze(arr,sol,sr,sc,dr,dc,stage);
    q1.maze_game(sol,sol1,sr,sc,dr,dc,stage);

}
