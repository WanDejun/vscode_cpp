pair<i64, i64> h[300003];
i64 n;

pair<i64, i64> top() {
	return h[1];
}
bool check(i64 a, i64 b) { //b在a前
	return (h[b].second > h[a].second || (h[b].second == h[a].second && h[b].first < h[a].first));
}
void adjust(i64 i) {
	if ((i << 1) <= n) {
		pair<i64, i64> t = h[i];
		if ((i << 1) + 1 <= n && check(i << 1, (i << 1) + 1)) {
			if (check(i, (i << 1) + 1)) {
				h[i] = h[(i << 1) + 1];
				h[(i << 1) + 1] = t;
				adjust(((i << 1) + 1));
			}
		}
		else {
			if (check(i, i << 1)) {
				h[i] = h[(i << 1)];
				h[i << 1] = t;
				adjust((i << 1));
			}
		}
	}
}
void sort() {
	for (i64 i = n >> 1; i > 0; i--) {
		adjust(i);
	}
}