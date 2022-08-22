// First time
bool isPalindrome(int x){
    long reverse = 0;
    int num = x;
    if (x < 0)
        return false;
    else
    {
        while (x != 0)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (num == reverse ? true : false);
    }
}