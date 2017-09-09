//https://www.youtube.com/watch?v=uCsD3ZGzMgE
int j(int n, int k) {
  if (n == 1) return 0;
  if (n < k) return (j(n-1,k)+k)%n;
  int np = n - n/k;
  return k*((j(np,k)+np-n%k%np)%np) / (k-1); 
}
