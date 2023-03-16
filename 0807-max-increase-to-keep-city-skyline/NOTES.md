max in row and column
​
```
for(int i=0; i<n; i++){
for(int j=0; j<n; j++){
row[i]=max(row[i], grid[i][j]);
col[j]=max(col[j], grid[i][j]);
}
}
```