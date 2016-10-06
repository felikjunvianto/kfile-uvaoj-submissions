var x,y,z,a,b,temp:longint;
	alice,betty:array[1..100000] of longint;
	
begin
	repeat
		readln(a,b);
		if((a <> 0)and(b<>0)) then
		begin
			fillchar(alice,sizeof(alice),0);
			fillchar(betty,sizeof(betty),0);
			
			for x:=1 to a-1 do
			begin
				read(temp);
				inc(alice[temp]);
			end;
			readln(temp);
			inc(alice[temp]);
			
			for x:=1 to b-1 do
			begin
				read(temp);
				inc(betty[temp]);
			end;
			readln(temp);
			inc(betty[temp]);
			y:=0;
			z:=0;
			a:=100000;
			b:=100000;
			while alice[a] = 0 do dec(a);
			while betty[b] = 0 do dec(b);
			
			for x:=1 to a do if ((alice[x]<>0)and(betty[x]=0)) then inc(y);
			for x:=1 to b do if ((alice[x]=0)and(betty[x]<>0)) then inc(z);
			temp:=y;
			if z<temp then temp:=z;
			writeln(temp);
		end;
	until((a=0)and(b=0));
end.