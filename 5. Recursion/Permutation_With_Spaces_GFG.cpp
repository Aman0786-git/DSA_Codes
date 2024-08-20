//Permutaion with Spaces-gfg
/*
IP-"ABC"
OP-"{
	A B C,
	A BC,
	AB C,
	ABC

}"
*/
void solve(string ip, string op, vector<string>&ans) {
	//getting the ans when ip lenght is 0
	if (ip.length() == 0) {
		ans.push_back(op);
		return ;
	}
	//Creating copies of op - op1 nd op2
	string op1 = op;
	string op2 = op;
	//Taking space nd element in one output
	op1.push_back(' ');
	op1.push_back(ip[0]);
	//Not taking space in other output
	op2.push_back(ip[0]);
	//removing first character from input
	ip.erase(ip.begin() + 0);
	solve(ip, op1, ans);
	solve(ip, op2, ans);
	return;
}
vector<string> permutation(string s) {
	// Code Here
	string op;
	vector<string>ans;
	//initializing output with first char as there is only one choice
	//cz no first or last spaces in string
	op = s[0];
	//removing first character from input
	s.erase(s.begin() + 0);
	solve(s, op, ans);
	return ans;
}
