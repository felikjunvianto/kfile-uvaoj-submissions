var m,n,x,y:longint;
	peta:array[1..100,1..100] of char;
	count:longint;
	
procedure isi(x,y:longint);
	var ver,hor:longint;
	
	begin
		peta[x,y]:='*';
		for hor:=-1 to 1 do
			for ver:=-1 to 1 do
				if((hor<>0)or(ver<>0)) then
					if((x+hor>=1)and(x+hor<=n)and(y+ver>=1)and(y+ver<=m)) then
						if peta[x+hor,y+ver]='@' then isi(x+hor,y+ver);
	end;
	
begin
	repeat
		readln(m,n);
		if((m<>0)and(n<>0)) then
		begin
			count:=0;
			fillchar(peta,sizeof(peta),'*');
			for y:=1 to m do
			begin
				for x:=1 to n do read(peta[x,y]);
				readln;
			end;
			
			for y:=1 to m do
				for x:=1 to n do
					if peta[x,y]='@' then
					begin
						inc(count);
						isi(x,y);
					end;
			writeln(count);
		end;
	until((m=0)or(n=0));
end.