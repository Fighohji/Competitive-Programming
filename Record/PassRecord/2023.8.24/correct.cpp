#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        vector<string> b(n+5);
        vector<vector<int>> a(n+5,vector<int>(n+5));
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            b[i]=' '+s;
        }
        int co=0,cx=0;
        vector<pair<int,int>> po,px;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i][j]=='o')
                    co++,po.emplace_back(i,j);
                else if(b[i][j]=='x')
                    cx++,px.emplace_back(i,j);
            }
        }
        auto chk=[&](int x){return 1<=x and x<=n;};
        int wo=0,wx=0;
        auto line=[&](int x,int y,int dx,int dy,char ch)
        {
            if(not chk(x+dx*(k-1)) or not chk(y+dy*(k-1)))return;
            for(int i=0;i<k;i++)
            {
                if(b[x+dx*i][y+dy*i]!=ch)return;
            }
            for(int i=0;i<k;i++)
            {
                a[x+dx*i][y+dy*i]++;
            }
            if(ch=='o')wo++;
            else wx++;
        };
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                line(i,j,1,0,'o');
                line(i,j,1,0,'x');
                line(i,j,1,1,'o');
                line(i,j,1,1,'x');
                line(i,j,0,1,'o');
                line(i,j,0,1,'x');
                line(i,j,1,-1,'o');
                line(i,j,1,-1,'x');
            }
        }
        if(wo and wx)
        {
            cout<<"NIE"<<endl;
        }
        else if(not wo and not wx)
        {
            if(co+cx==n*n)
            {
                if(co==cx)//x first
                {
                    cout<<"TAK"<<endl;
                    for(int i=0;i<cx;i++)
                    {
                        cout<<px[i].first<<' '<<px[i].second<<"\n";
                        cout<<po[i].first<<' '<<po[i].second<<"\n";
                    }
                }
                else if(co==cx+1)//o first
                {
                    cout<<"TAK"<<endl;
                    for(int i=0;i<cx;i++)
                    {
                        cout<<po[i].first<<' '<<po[i].second<<"\n";
                        cout<<px[i].first<<' '<<px[i].second<<"\n";
                    }
                    cout<<po[co-1].first<<' '<<po[co-1].second<<"\n";
                }
                else if(cx==co+1)//x first
                {
                    cout<<"TAK"<<endl;
                    for(int i=0;i<co;i++)
                    {
                        cout<<px[i].first<<' '<<px[i].second<<"\n";
                        cout<<po[i].first<<' '<<po[i].second<<"\n";
                    }
                    cout<<px[cx-1].first<<' '<<px[cx-1].second<<"\n";
                }
                else
                {
                    cout<<"NIE"<<endl;
                }
            }
            else
            {
                cout<<"NIE"<<endl;
            }
        }
        else if(wo)
        {
            int tx=0,ty=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[i][j]==wo)
                    {
                        tx=i;ty=j;
                    }
                }
            }
            if(tx==0)
            {
                cout<<"NIE"<<endl;
            }
            else
            {
                for(int i=0;i<co;i++)
                {
                    if(po[i]==make_pair(tx,ty))
                    {
                        swap(po[i],po[co-1]);
                        break;
                    }
                }
                if(co==cx)//x first
                {
                    cout<<"TAK"<<endl;
                    for(int i=0;i<cx;i++)
                    {
                        cout<<px[i].first<<' '<<px[i].second<<"\n";
                        cout<<po[i].first<<' '<<po[i].second<<"\n";
                    }
                }
                else if(co==cx+1)//o first
                {
                    cout<<"TAK"<<endl;
                    for(int i=0;i<cx;i++)
                    {
                        cout<<po[i].first<<' '<<po[i].second<<"\n";
                        cout<<px[i].first<<' '<<px[i].second<<"\n";
                    }
                    cout<<po[co-1].first<<' '<<po[co-1].second<<"\n";
                }
                else
                {
                    cout<<"NIE"<<endl;
                }
            }
        }
        else //wx
        {
            int tx=0,ty=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[i][j]==wx)
                    {
                        tx=i;ty=j;
                    }
                }
            }
            if(tx==0)
            {
                cout<<"NIE"<<endl;
            }
            else
            {
                for(int i=0;i<cx;i++)
                {
                    if(px[i]==make_pair(tx,ty))
                    {
                        swap(px[i],px[cx-1]);
                        break;
                    }
                }
                if(cx==co)//o first
                {
                    cout<<"TAK"<<endl;
                    for(int i=0;i<co;i++)
                    {
                        cout<<po[i].first<<' '<<po[i].second<<"\n";
                        cout<<px[i].first<<' '<<px[i].second<<"\n";
                    }
                }
                else if(cx==co+1)//x first
                {
                    cout<<"TAK"<<endl;
                    for(int i=0;i<co;i++)
                    {
                        cout<<px[i].first<<' '<<px[i].second<<"\n";
                        cout<<po[i].first<<' '<<po[i].second<<"\n";
                    }
                    cout<<px[cx-1].first<<' '<<px[cx-1].second<<"\n";
                }
                else
                {
                    cout<<"NIE"<<endl;
                }
            }
        }
    }
    
    return 0;
}
