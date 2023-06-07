
# Online Python - IDE, Editor, Compiler, Interpreter

def main():
    t = int(input())
    
    while t > 0:
        n, q = input().split()
        n, q = int(n), int(q)
        even, odd = 0, 0
        sum = 0
        
        for num in input().split():
            num = int(num)
            sum += num
            
            if num % 2 == 0:
                even += 1
            else:
                odd += 1
        
        while q > 0:
            qtype, x = input().split()
            qtype, x = int(qtype), int(x)
            
            if qtype == 0:
                sum += x * even
                
                if x % 2 != 0:
                    odd += even
                    even = 0
            else:
                sum += x * odd
                
                if x % 2 != 0:
                    even += odd
                    odd = 0
                    
            print(sum)
            q -= 1
            
        t -= 1
    
main()
