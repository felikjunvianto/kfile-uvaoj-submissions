var x:longint;

function f91(n:longint):longint;
	begin
		if n<=100 then f91:=f91(f91(n+11)) else f91:=n-10;
	end;

begin
	repeat
		readln(x);
		if x<>0 then writeln('f91(',x,') = ',f91(x));
	until x=0;
end.