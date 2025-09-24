from decimal import Decimal ,getcontext
class Solution(object):
    def ck(self,numr,denr):
        m={}
        rem = numr % denr
        res=""
        while((rem!=0) and (rem not in m)):
            m[rem]=len(res)
            rem=rem*10
            res =res+str(rem//denr)
            rem=(rem)%denr
        if rem==0:
            return "",""
        else:
            return res[m[rem]:] ,res[:m[rem]]   



    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        getcontext().prec=10000
        f=0
        if numerator<0 or denominator<0:
            if numerator<0 and denominator<0:
                f=0
            elif numerator==0:
                f=0
            else:
                f=1

        numerator=abs(numerator)
        denominator=abs(denominator)
        k,r=self.ck(numerator,denominator)
        if k=="":
            numerator=Decimal (numerator)
            denominator=Decimal (denominator)
            b=numerator/denominator
            if numerator%denominator==0:
                b=int(b)
            b = format(b, 'f').rstrip('0').rstrip('.')   # fixed-point notation, no scientific form
            if f==1:
                b="-"+b
            return b
        else:
            b=numerator/denominator
            b=format(b, 'f').rstrip('0').rstrip('.')+"."+r+"("+k+")"
            if f==1:
                b="-"+b
            return b 

        