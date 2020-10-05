#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[502][502];
int n, m;
bool vis[502][502];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
void show_board()
{
    for(int x=0; x<n; x++)
    {    for(int y=0; y<m; y++)
            cout<<board[x][y]<<' ';
        cout<<'\n';
    }   
}
void board_input()
{
    int t;
    for(int x = 0; x<n; x++)
    {
        for(int y=0; y<m; y++)
        {
            cin>>t;
            board[x][y] = t;
        }
    }
}
//
bool isOutOfRange(int tx, int ty)
{
    if(tx<0 || tx>=n || ty<0 || ty>=m)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    board_input();
    queue<pair<int, int>> Q;
    int maxium_pic =-1;//그림의 최대 넓이
    int piece = 0;     //그림의 갯수
    int pic_area = 0;  //그림의 넓이 == pop 한 숫자
    for(int x= 0; x<n; x++)
    {
        for(int y=0; y<m; y++)
        {
            if(vis[x][y]==0 && board[x][y]!=0)
            {   
                piece++;
                vis[x][y] = 1;
                Q.push({x,y});
            }
            
            while(!Q.empty())
            {
                pair<int,int> cur = Q.front(); Q.pop();
                pic_area++;    
                for(int i=0; i<4; i++)
                {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(isOutOfRange(nx, ny)) continue;
                    if(board[nx][ny]==0 || vis[nx][ny]==1) continue;                    
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            if(maxium_pic<pic_area)
                maxium_pic = pic_area;
            pic_area = 0;
        }
    }
    cout<<piece<<'\n'<<maxium_pic<<'\n';
    return 0;
}