import sys
sys.stdin = open('input.in', 'r')
sys.stdout = open('output.out', 'w')

def main():
  print('hi')
  n = int(input())
  for i in range(n):
      a, b = map(int, input().split())
      print(a, b)



if __name__ == "__main__":
    main()