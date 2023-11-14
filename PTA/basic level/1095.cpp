#include <bits/stdc++.h>

#define pii array<i64, 2>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define FI first
#define SE second
#define i64 long long

using namespace std;

const i64 N = 1e4 + 5;
const i64 MOD = 998244353;
char level[N];
i64 cls_id[N], date[N], stu_id[N], score[N];
i64 t_id[N], t_score[N], n, kk;
map<i64, i64> mp;
pii a[N];

void input(int i) {
    level[i] = getchar();
    char c;
    i64 t = 0;
    for (int j = 0; j < 3; j++) {
        c = getchar() - '0';
        t = t * 10 + c;
    } cls_id[i] = t; t = 0;

    for (int j = 0; j < 6; j++) {
        c = getchar() - '0';
        t = t * 10 + c;
    } date[i] = t; t = 0;

    for (int j = 0; j < 3; j++) {
        c = getchar() - '0';
        t = t * 10 + c;
    } stu_id[i] = t; t = 0;
    scanf("%lld", score + i);
    getchar();
}

void qsort_sub(i64 st, i64 ed) {
    if (st >= ed) return;
    i64 l = st, r = ed, p_id = t_id[l], p_score = t_score[l];
    while (l < r) {
        while (l < r && (t_score[r] == p_score ? t_id[r] >= p_id : t_score[r] < p_score)) 
            r--;
        t_id[l] = t_id[r]; t_score[l] = t_score[r]; 
        while (l < r && (p_score == t_score[l] ? p_id >= t_id[l] : p_score < t_score[l])) 
            l++;
        t_id[r] = t_id[l]; t_score[r] = t_score[l];
    }
    t_id[r] = p_id;
    t_score[r] = p_score;
    qsort_sub(st, l - 1); qsort_sub(l + 1, ed);
}

void qsort(char lv) {
    i64 m = 0;
    for (i64 i = 0; i < n; i++) {
        if (level[i] == lv) {
            t_id[m] = cls_id[i] * 1e9 + date[i] * 1e3 + stu_id[i];
            t_score[m] = score[i];
            m++;
        }
    }
    qsort_sub(0, m - 1);
    m = 0;
    for (i64 i = 0; i < n; i++) {
        if (level[i] == lv) {
            stu_id[i] = t_id[m] % static_cast<i64>(1e3); t_id[m] /= 1e3;
            date[i] = t_id[m] % static_cast<i64>(1e6); t_id[m] /= 1e6;
            cls_id[i] = t_id[m]; t_id[m] /= 1e3;
            score[i] = t_score[m];
            m++;
        }
    }
}

void init_sort() {
    char s[3] = {'A', 'B', 'T'};
    for (int i = 0; i < 3; i++) {
        qsort(s[i]);
    } 
}

void case1(char c) {
    bool flag = 0;

    for (i64 i = 0; i < n; i++) {
        if (level[i] == c) {
            printf("%c%03lld%03lld%03lld %lld\n", c, cls_id[i], date[i], stu_id[i], score[i]);
            flag = 1;
        }
    }
    if (!flag) printf("NA\n");
}

void case2(i64 t) {
    i64 sum = 0, cnt = 0;

    for (i64 i = 0; i < n; i++) {
        if (cls_id[i] == t) {
            cnt++;
            sum += score[i];
        }
    }
    if (cnt == 0) printf("NA\n");
    else printf("%lld %lld\n", cnt, sum);
}

void case3(i64 t) {
    i64 sum = 0, cnt = 0;

    mp.clear();
    for (i64 i = 0; i < n; i++) {
        if (date[i] == t) {
            mp[cls_id[i]]++;
        }
    }
    i64 m = 0;
    for (auto& it : mp) {
        a[m][0] = it.first;
        a[m][1] = it.second;
        m++;
    }
    if (m == 0) {
        printf("NA\n");
        return;
    }
    sort(a, a + m, [](pii &a, pii &b) {return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];});
    for (i64 i = 0; i < m; i++) {
        printf("%lld %lld\n", a[i][0], a[i][1]);
    }
}

void solve() {
    i64 x, y, q;
    scanf("%lld%lld", &n, &q); getchar();
    for (i64 i = 0; i < n; i++) {
        input(i);
    }
    init_sort();
    i64 opcode, num;
	char c;
    for (i64 i = 0; i < q; i++) {
        scanf("%lld", &opcode);
        kk++;
        switch (opcode) {
        case 1:
        	c = getchar();
        	while (c == ' ') c = getchar(); getchar();
        	printf("Case %lld: 1 %c\n", kk, c);
            case1(c);
            break;
        case 2:
        	num = 0; c = getchar();
        	printf("Case %lld: 2 ", kk);
        	while (c != '\n') {
        		c = getchar(); putchar(c);
        		if (c != ' ' && c != '\n') num = num * 10 + (c - '0');
        	}
            case2(num);
            break;
        case 3:
       		num = 0; c = getchar();
        	printf("Case %lld: 3 ", kk);
        	while (c != '\n') {
        		c = getchar(); putchar(c);
        		if (c != ' ' && c != '\n') num = num * 10 + (c - '0');
        	}
            case3(num);
            break;
        default:
            printf("Case %lld: %lld", kk, opcode);

            while (c != '\n' && c != '\r') {putchar(c); c = getchar(); }
            printf("\nNA\n");
            break;
        }
    }
}
signed main() {
    solve();

    system("pause");
    return 0;
}
