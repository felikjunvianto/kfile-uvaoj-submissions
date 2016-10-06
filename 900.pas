var x:longint;
	brick:array[1..50] of qword;
	
function fibo(x:longint):qword;
	begin
		if brick[x]=0 then brick[x]:=fibo(x-1)+fibo(x-2);
		fibo:=brick[x];
	end;
	
begin
	fillchar(brick,sizeof(brick),0);
	brick[1]:=1;
	brick[2]:=2;
	repeat
		readln(x);
		if x>0 then writeln(fibo(x));
	until x=0;
end.