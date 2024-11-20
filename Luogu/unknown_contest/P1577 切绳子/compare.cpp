#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define rep(i,a,b) for(auto i=(a);i<=(b);i++)
#define repp(i,a,b) for(auto i=(a);i<(b);i++)
#define per(i,a,b) for(auto i=(a);i>=(b);i--)
#define perr(i,a,b) for(auto i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define mst(a,b) memset(a,b,sizeof(a))
#define pb push_back

// ================================================

#define Status int
#define AC 0
#define WA 1
#define PE -1

#ifndef MAX_PATH
#define MAX_PATH 1023
#endif

struct FilePointer {
    FILE *f;
    bool read(int &x) {
        return fscanf(f, "%d", &x) != EOF;
    }
    bool read(long long &x) {
        return fscanf(f, "%lld", &x) != EOF;
    }
    bool read(double &x) {
        return fscanf(f, "%lf", &x) != EOF;
    }
    bool readString(char *s, int maxLength) {
        string format = "%" + to_string(maxLength) + "s";
        return fscanf(f, format.c_str(), s) != EOF;
    }
    bool expectEOF() {
        char x[2];
        return fscanf(f, "%1s", x) == EOF;
    }
} fin, fout, fans, ferr;

void openFiles() {
    char in[MAX_PATH], ans[MAX_PATH], out[MAX_PATH], err[MAX_PATH];
    gets(in); gets(ans); gets(out); gets(err);
    if((fin.f = fopen(in, "r")) == NULL)
        fprintf(stderr, "System Error: Can not open %s!\n", in);
    if((fans.f = fopen(ans, "r")) == NULL)
        fprintf(stderr, "System Error: Can not open %s!\n", ans);
    if((fout.f = fopen(out, "r")) == NULL)
        fprintf(stderr, "System Error: Can not open %s!\n", out);
    if((ferr.f = fopen(err, "w")) == NULL)
        fprintf(stderr, "System Error: Can not open %s!\n", err);
}

inline void floatValidator(double ans, double out, double eps, bool showData = true, int cas = 0) {
    if(isnan(out)) {
        if(!cas) fprintf(ferr.f, "Wrong Answer - found: 'nan'.", ans);
        else     fprintf(ferr.f, "Wrong Answer on case #%d - found: 'nan'.", cas);
        exit(WA);
    }
    double err = fabs(ans - out) / max(1.0, fabs(ans));
    if(err > eps && fabs(ans - out) > 0.01) {
        if(showData) {
            if(!cas) fprintf(ferr.f, "Wrong Answer - expected: '%.10f', found: '%.10f', error = '%.10f'.", ans, out, err);
            else     fprintf(ferr.f, "Wrong Answer on case #%d - expected: '%.10f', found: '%.10f', error = '%.10f'.", cas, ans, out, err);
        }
        else {
            if(!cas) fprintf(ferr.f, "Wrong Answer - the error between your answer and Jury's answer exceeds the limit.");
            else     fprintf(ferr.f, "Wrong Answer on case #%d - the error between your answer and Jury's answer exceeds the limit.", cas);
        }
        exit(WA);
    }
}

void errout(int type, int cas = 0) {
    switch(type) {
        case 0:
            fprintf(ferr.f, "Redundant outputs.");
            return;
        case 1:
            if(cas) fprintf(ferr.f, "Wrong Answer on case #%d - insufficient output quantity.", cas);
            else    fprintf(ferr.f, "Wrong Answer - insufficient output quantity.");
            return;
        case 2:
            if(cas) fprintf(ferr.f, "Wrong Answer on case #%d - your output is not within the range.", cas);
            else    fprintf(ferr.f, "Wrong Answer - your output is not within the range.");
            return;
        case 3:
            if(cas) fprintf(ferr.f, "Wrong Answer on case #%d - your output format does not match the requirement.", cas);
            else    fprintf(ferr.f, "Wrong Answer - your output format does not match the requirement.");
            return;
        case 4:
            if(cas) fprintf(ferr.f, "Wrong Answer on case #%d - your solution does not match the requirement.", cas);
            else    fprintf(ferr.f, "Wrong Answer - your solution does not match the requirement.");
            return;
        case 5:
            if(cas) fprintf(ferr.f, "Wrong Answer on case #%d - Jury has a better solution.", cas);
            else    fprintf(ferr.f, "Wrong Answer - Jury has a better solution.");
            return;
        default:
            return;
    }
}

// ================================================

Status specialJudge() {
    double x, y;
    fans.read(x); // 测试点.out文件内的数据
    if(!fout.read(y)) { // 用户实际输出的数据
        errout(1);
        return WA; // 无可读的输出内容
    }
    floatValidator(x, y, 1e-2); // 误差超出预期

    // ============================================

    if(!fout.expectEOF()) { // 不允许输出多余内容，空格和换行除外
        errout(0);
        return WA;
    }
    return AC;
}

Status main() {
    openFiles();
    return specialJudge();
}
