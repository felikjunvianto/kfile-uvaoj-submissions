var n,m,x:longint;

function pangkat(acu:longint):longint;
	var x:longint;
	
	begin
		pangkat:=1;
		for x:=1 to acu do pangkat:=pangkat*16;
	end;

function binhex(m:longint):longint;
	var temp:string;
		x:longint;
	
	begin
		str(m,temp);
		m:=0;
		for x:=1 to length(temp) do m:=m+(ord(temp[x])-ord('0'))*pangkat(x-1);
		binhex:=0;
		repeat
			if m mod 2 = 1 then inc(binhex);
			m:=m div 2;
		until m=0;
	end;

function bindes(m:longint):longint;
	begin
		bindes:=0;
		repeat
			if m mod 2 =1 then inc(bindes);
			m:=m div 2;
		until m=0;
	end;

begin
	readln(n);
	for x:=1 to n do
	begin
		readln(m);
		writeln(bindes(m),' ',binhex(m));
	end;
end.