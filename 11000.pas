var n,x:longint;
	fibo_sum:array[-1..45] of longword;
	
function fibo(x:longint):longint;
	var temp:array[0..45] of longword;
		y:longint;
		
	begin
		temp[0]:=1;
		temp[1]:=1;
		for y:=2 to x do temp[y]:=temp[y-1]+temp[y-2];
		fibo:=temp[x];
	end;
	
begin
	fibo_sum[-1]:=0;
	fibo_sum[0]:=1;
	
	for x:=1 to 45 do fibo_sum[x]:=fibo_sum[x-1]+fibo(x);
	
	repeat
		readln(n);
		if n<>-1 then writeln(fibo_sum[n-1],' ',fibo_sum[n]);
	until n=-1;
end.