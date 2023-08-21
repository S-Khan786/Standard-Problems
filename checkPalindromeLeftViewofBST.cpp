
/*Problem*/
/*System give me node value and using those values we make BST
After that find left View of it 
and check it is Palindrome or not*/
#include<bits/stdc++.h>
using namespace std;

void bournVita() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		data = 0;
		left = right = NULL;
	}

	TreeNode(int x) {
		data = x;
		left = right = NULL;
	}

	TreeNode(int x, TreeNode* l, TreeNode* r) {
		data = x;
		left = l;
		right = r;
	}
};

TreeNode* root = new TreeNode();

TreeNode* help(TreeNode* root, int x) {
	if(root == NULL) {
		return new TreeNode(x);
	}

	if(root->data > x) {
		root->left = help(root->left, x);

	}
	else {
		root->right = help(root->right, x);
	}

	return root;
}

string s = "";
void leftView(TreeNode* root) {
	if(root == NULL) {
		return;
	}

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		int n = q.size();
		
		//cout << n << endl;
		for(int i=0; i<n; i++) {
			TreeNode* curr = q.front();
			q.pop();

			if(i == 0) {
				s += curr->data + '0';
			}

			if(curr->left != NULL) {
				q.push(curr->left);
			}
			
			if(curr->right != NULL) {
				q.push(curr->right);
			}
		}
	}
}

bool checkPalindrome(string s) {	
	int n = s.size();

	for(int i=0; i<(n / 2); i++) {

		if(s[i] != s[n - i - 1]) {
			return false;
		}
	}
	
	return true;
}

void solve1(){
	int n;
	cin >> n;

	int x; cin >> x;
	root->data = x;

	for(int i=1; i<n; i++) {
		int x; cin >> x;
		root = help(root, x);
	}

	leftView(root);

	cout << s << endl;
	if(checkPalindrome(s)) {
		cout << "Yes" << endl; 
	}
	else {
		cout << "No" << endl;
	}
}

int32_t main() {

	bournVita();
	
	solve1();

	return 0;
}
