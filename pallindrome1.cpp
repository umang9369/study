

bool palindrome(int n) {
    string s  = to_string(n);
    string target =  s;
    reverse(s.begin() , s.end());
    if(s == target) {
        return true;
    } else {
        return false;
    }

}

int main() {
    cout << palindrome(12121) << endl;
    return 0;
}
