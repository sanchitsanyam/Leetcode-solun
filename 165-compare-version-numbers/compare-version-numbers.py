
class Solution(object):
    
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        t1=version1.split('.')
        t2=version2.split('.')
        m=max(len(t1),len(t2))
        for i in range(m):
            if i<len(t1):
                st1=t1[i]
            else:
                st1=None    

            if i<len(t2):
                st2=t2[i]
            else:
                st2=None    
            x,y=0,0
            if st1!=None:
                x=int(st1)
            if st2!=None:
                y=int(st2)    
            
            if x==y and i!=m-1:
                continue
            elif x==y:
                return 0
            elif x>y:
                return 1
            elif x<y:
                return -1    

        
        