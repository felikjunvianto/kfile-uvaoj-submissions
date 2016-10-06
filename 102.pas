const kata:array[1..3] of char=('B','G','C');

var x,y:longint;
	temp,min:longword;
	bin:array[1..3,1..3] of longword;
	used:array[1..3] of boolean;
	perm,semen:string;
	list:array[1..3] of longint;
	
procedure cekbin;
	var x,y:longint;
	
	begin
		semen:='';
		for x:=1 to 3 do semen:=semen+kata[list[x]];
		temp:=0;
		for x:=1 to 3 do
			for y:=1 to 3 do if y<>list[x] then inc(temp,bin[x,y]);
		
		if((temp<min)or((temp=min)and(semen<perm))) then
		begin
			perm:=semen;
			min:=temp;
		end;
	end;
	
procedure permutasi(t:longint);
	var y:longint;
	
	begin
		if t=4 then cekbin else
			for y:=1 to 3 do if used[y] then
			begin
				list[t]:=y;
				used[y]:=FALSE;
				permutasi(t+1);
				used[y]:=TRUE;
			end;
	end;
	
begin
	while not(eof) do
	begin
		min:=0;
		for x:=1 to 3 do
		begin
			used[x]:=TRUE;
			for y:=1 to 3 do 
			begin
				read(bin[x,y]);
				inc(min,bin[x,y]);
			end;
		end;
		readln;
		
		perm:='GGG';
		permutasi(1);
		writeln(perm,' ',min);
	end;
end.