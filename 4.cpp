
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main () {
  vector <int> z;
  string s, t;
	cin >> s >> t;
	s += "#" + t;
	int n = s.size();
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z.push_back(min(r - i + 1, z[i - l]));
		while (i + z[i] < n && s[z[i]] == s[z[i] + i])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	for (int j = 0, i = t.size() + 1; i < s.size(); ++j, ++i) {
		if (j + z[i] == t.size()) {
			cout << "Yes\n" << j;
			return 0;
		}
	}

	return 0;
}
