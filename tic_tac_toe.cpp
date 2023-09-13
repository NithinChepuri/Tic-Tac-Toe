Note- Codes for mXn and 3X3 are provided respectively.



CODE FOR mXn code:





#include<iostream>
using namespace std;
int checkrow(char[][100],int,int,int);
int checkcoloumn(char[][100],int,int,int);
int checkrupdiagonal(char[][100],int,int,int);
int checkrdowndiagonal(char[][100],int,int,int);
int checklupdiagonal(char[][100],int,int,int);
int checkldowndiagonal(char[][100],int,int,int);

int main()
{
    char a[100][100];
    int m,n,k,p,q,x,y,i,r;
    cout<<"                                |TIC TAC TOE|"<<endl;
    cout<<"Enter dimensions of the box  "<<endl;
    cout<<"Enter number of rows : ";
    cin>>m;
    cout<<"Enter number of columns : ";
    cin>>n;
    cout<<"Enter number (k accordingly) ";
    cin>>k;
    cout<<"Board accoding to chosen dimension:"<<endl;
    for(x=0;x<m;x++){
        for(y=0;y<n;y++)
        a[x][y]='*';
    }
    for(x=0;x<m;x++){
        for(y=0;y<n;y++)
        cout<<a[x][y]<<" ";
        
        cout<<endl;
    }
    cout<<"Rules :"<<endl;
    cout<<"   1)  Player 1 is assigned by X & player 2 by O "<<endl;
    cout<<"   2)  Please try to enter valid row number and column numbers(rows and columns begin with 0)"<<endl;
    cout<<"   3)  Enter capital letters i.e (X,O)"<<endl;
    for(i=0;i<m*n;i++)
    {
        cout<<"Enter row number-";
        cin>>p;
        cout<<"Enter column number-";
        cin>>q;
       if(a[p][q]=='X' || a[p][q]=='O')
        {
           cout<<"Invalid move "<<endl;
           i=i-1;
        }
        else if(p>=m || q>=n )
        {
           cout<<"Invalid move"<<endl;
           i=i-1;
        }
        else
        {
            cout<<"Enter X/O :";
            cin>>a[p][q];
            r=checkrow(a,m,n,k);
            {
                if(r==1)
                {
                    cout<<"Player 1 is winner "<<endl;
                    break;
                }
                else if(r==2)
                {
                    cout<<"Player 2 is winner"<<endl;
                    break;
                }
                else
                {
                    i=i+0;
                }
            }
            r=checkcoloumn(a,m,n,k);
            {
                if(r==1)
                {
                    cout<<"Player 1 is winner "<<endl;
                    break;
                }
                else if(r==2)
                {
                    cout<<"Player 2 is winner"<<endl;
                    break;
                }
                else
                {
                    i=i+0;
                }
            }
            r=checkrupdiagonal(a,m,n,k);
            {
                if(r==1)
                {
                    cout<<"Player 1 is winner "<<endl;
                    break;
                }
                else if(r==2)
                {
                    cout<<"Player 2 is winner"<<endl;
                    break;
                }
                
            }
            r=checkrdowndiagonal(a,m,n,k);
            {
                if(r==1)
                {
                    cout<<"Player 1 is winner "<<endl;
                    break;
                }
                else if(r==2)
                {
                    cout<<"Player 2 is winner"<<endl;
                    break;
                }
            }
            r=checklupdiagonal(a,m,n,k);
            {
                if(r==1)
                {
                    cout<<"Player 1 is winner "<<endl;
                    break;
                }
                else if(r==2)
                {
                    cout<<"Player 2 is winner"<<endl;
                    break;
                }
            }
            r=checkldowndiagonal(a,m,n,k);
            {
                if(r==1)
                {
                    cout<<"player 1 is winner "<<endl;
                    break;
                }
                else if(r==2)
                {
                    cout<<"player 2 is winner"<<endl;
                    break;
                }
            }
            cout<<endl;
            
            for(x=0;x<m;x++)
            {
                for(y=0;y<n;y++)
                {
                    cout<<a[x][y]<<" ";
                }
                cout<<endl;
            }
       }
    }
    cout<<"Final board"<<endl;
    for(x=0;x<m;x++){
        for(y=0;y<n;y++)
        cout<<a[x][y]<<" ";
        
        cout<<endl;
    }
    
    if(i == m*n)
    cout<<"Game is draw"<<endl;
    
    return 0;
}
int checkrow(char a[][100],int m,int n,int k)
{
    int s,result=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            s=0;
            for(int r=j;r<j+k;r++){
                s=s+int(a[i][r]);
                if(s==88*k)
                {
                    result=1;
                    break;
                }
                else if(s==79*k)
                {
                    result=2;
                    break;
                }
            }
            if(result==1 || result==2)
            break;
        }
        if(result==1 ||result==2)
        break;
    }
    
    return result;
}
int checkcoloumn(char a[][100],int m,int n,int k)
{
     int s=0,result=0;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            s=0;
            for(int r=i;r<i+k;r++)
            {
                s=s+int(a[r][j]);
                if(s==88*k)
                {
                    result=1;
                    break;
                }
                else if(s==79*k)
                {
                    result=2;
                    break;
                }
            }
            if(result==1 || result==2)
            break;
        }
        if(result==1 || result==2)
        break;
    }
    return result;
}
int checkrupdiagonal(char a[][100],int m,int n,int k)
{
    int i,j,b,p,s,result=0;
    for(i=0;i<m;i++)
    {
        b = i;
        for(j=0;j<n;j++)
        {
            if(b<m)
            {
                s=0;
                for(p=j;p<j+k;p++)
                {
                    s = s+ int(a[b][p]);
                    b--;
                }
                if(s==88*k)
                {
                    result=1;
                    break;
                }
                else if(s==79*k)
                {
                    result=2;
                    break;
                }
                b=b+k-1;
            }
        }
        if(result==1 ||result==2)
        break;
    }
    return result;
}
int checkrdowndiagonal(char a[][100],int m,int n,int k)
{
    int i,j,b,p,result=0,s;
    for(i=0;i<m;i++)
    {
        b = i;
        for(j=0;j<n;j++)
        {
            
            if(b<m)
            {
                
                s=0;
                for(p=j;p<j+k;p++)
                {
                    s = s+ int(a[b][p]);
                    b++;
                }
                if(s==88*k)
                {
                  result=1;
                  break;
                }
                else if(s==79*k)
                {
                    result=2;
                    break;
                }
                b=b-k+1;
            }
        }
        if(result==1 ||result==2)
        result;
    }
    return result;
}
int checklupdiagonal(char a[][100],int m,int n,int k)
{
    int b,c,s=0,result=0;
    for(int i=0;i<m;i++)
    {
        b=i;
        for(int j=n-1;j>=0;j--)
        {
            for(int v=j;v>j-k;v--)
            {
                s=s+int(a[b][v]);
                b--;
            }
            if(s==88*k)
            {
                result=1;
                break;
            }
            else if(s==79*k)
            {
                result=2;
                break;
            }
            else
            s=0;
            
            b=b+k-1;
        }
        if(result==1 ||result==2)
        break;
    }
    return result;
}
int checkldowndiagonal(char a[][100],int m,int n,int k)
{
    int i,j,b,p,s,result=0;
    for(i=0;i<m;i++)
    {
        b = i;
        for(j=n-1;j>-1;j--)
        {
            if(b>-1)
            {
                s=0;
                for(p=j;p>j-k;p--)
                {
                    s = s+ int(a[b][p]);
                    b++;
                }
                if(s==88*k)
                {
                    result=1;
                    break;
                }
                else if(s==79*k)
                {
                    result=2;
                    break;
                }
                b=b-k+1;
            }
        }
        if(result==1 ||result==2)
        break;
    }
    return result;
}




































CODE FOR 3X3




int rows(char A[3][3],int i,int j)
{
    int s=0,result=0;
    for(int b=0;b<3;b++)
    {
        s = s+ int(A[i][j]);
        i = (i+1)%3;
    }
    if(s==360)
    {
        result = 1;
    }
    else if(s==333)
    {
        result = 2;
    }
    else
    {
        result =0;
    }
    return result;
}

int columns( char A[3][3], int i, int j)
{
    int s=0,result=0;
    for(int b=0;b<3;b++)
    {
        s = s+ int(A[i][j]);
        j = (j+1)%3;
    }
    if(s==360)
    {
        result = 1;
    }
    else if(s==333)
    {
        result = 2;
    }
    else
    {
        result =0;
    }
    return result;
}

int diagonal( char A[3][3], int i, int j)
{
    int s=0,result;
    for(int b=0;b<3;b++)
    {
        s = s + int(A[i][j]);
        i= (i+4)%3;
        j=(j+4)%3;
        
    }
    if(s==360)
    {
        result = 1;
    }
    else if(s==333)
    {
        result = 2;
    }
    else
    {
        result =0;
    }
    return result;
}

int diagonal1( char A[3][3], int i, int j)
{
    int s=0,result;
    for(int b=0;b<3;b++)
    {
        s = s + int(A[i][j]);
        i= (i+2)%3;
        j=(j+1)%3;
        
    }
    if(s==360)
    {
        result = 1;
    }
    else if(s==333)
    {
        result = 2;
    }
    else
    {
        result =0;
    }
    return result;
}



int main()
{
    int a,b,c,d,e,f,g,h, result,z=1;
    int i,j;
    char A[3][3];
    for(int x=0;x<3;x++)
    {
        
        for(int y=0;y<3;y++)
        {
            A[x][y]='0';
        }
    }
    
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            cout<<A[x][y]<<" ";
        }
        cout<<endl;
    }
    
    for(a=0;a<9;a++)
    {
        cout<<"Enter position of player "<<z<<" in terms of i and j "<<endl;
        cin>>i;
        cin>>j;
        
        if(A[i][j]=='x' || A[i][j]=='o')
        {
            cout<<"Invalid move"<<endl;
            a=a-1;
        }
        else
        {
            cin>>A[i][j];
            result = rows(A,i,j);
            if(result==1)
            {
                cout<<"a is winner";
                break;
            }
            else if(result==2)
            {
                cout<< "b is winner";
                break;
            }
            else
            {
                result=result+0;
            }
            
            result = columns(A,i,j) + result;
            if(result==1)
            {
                cout<<"a is winner";
                break;
            }
            else if(result==2)
            {
                cout<< " b is winner";
                break;
            }
            else
            {
                result=result+0;
            }
            if(i==j)
            {
                result = diagonal(A,i,j)+ result;
                if(result==1)
                {
                    cout<<"a is winner";
                    break;
                }
                else if(result==2)
                {
                    cout<< " b is winner";
                    break;
                }
                else
                {
                    result=result+0;
                }
            }
            
            if(i+j==2)
            {
                result = diagonal(A,i,j)+ result;
                if(result==1)
                {
                    cout<<"a is winner";
                    break;
                }
                else if(result==2)
                {
                    cout<< " b is winner";
                    break;
                }
                else
                {
                    result=result+0;
                }
            }
            
            cout<<endl;
            for(int x=0;x<3;x++)
            {
                for(int y=0;y<3;y++)
                {
                    cout<<A[x][y]<<" ";
                }
                cout<<endl;
            }
            if(z==1)
            {
                z=2;
            }
            else
            {
                z=1;
            }
        }
        
    }
    
    if(a==9)
    cout<<"game is draw";
    cout<<endl;
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            cout<<A[x][y]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}