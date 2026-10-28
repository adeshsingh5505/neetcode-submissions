class Solution:
    def isPalindrome(self, s: str) -> bool:
        list1=s.split()
        str2=''.join(list1)
        str3=''.join(ch for ch in s if ch.isalnum())
        str3=str3.lower()
        i=0
        j=len(str3)-1
        while i<=j:
            if str3[i]!=str3[j]:
                return False
            i+=1
            j-=1
        return True