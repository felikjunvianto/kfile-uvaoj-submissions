const batas=4000000;

var a,b,n,max:longint;
	bil:array[1..batas] of longint;
	
function manual(x:longint):longint;
	begin
		manual:=1;
		while x>1 do
		begin
			case x mod 2 of
			0: x:=x div 2;
			1: x:=x*3+1;
			end;
			inc(manual);
		end;
	end;
	
function panjang(x:longint):longint;
	begin
		if x>batas then panjang:=manual(x) else
		begin
			if bil[x]=0 then
			begin
				if odd(x) then bil[x]:=1+panjang(3*x+1) else
					bil[x]:=1+panjang(x div 2);
			end;
			panjang:=bil[x];
		end;
	end;
	
function min(x,y:longint):longint;
	begin
		min:=x;
		if min>y then min:=y;
	end;
	
begin
	for n:=2 to batas do bil[n]:=0;
	bil[1]:=1;
	while not(eof) do
	begin
		readln(a,b);
		max:=0;
		for n:=min(a,b) to a+b-min(a,b) do
			if panjang(n)>max then max:=panjang(n);
			
		writeln(a,' ',b,' ',max);
	end;
end.