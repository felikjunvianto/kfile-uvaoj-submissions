var st1,st2:ansistring;
	x,z:longint;
	count1,count2:array['a'..'z'] of longint;
	a:char;
	
begin
	while not(eof) do
	begin
		readln(st1);
		readln(st2);
		fillchar(count1,sizeof(count1),0);
		fillchar(count2,sizeof(count2),0);
		for x:=1 to length(st1) do inc(count1[st1[x]]);
		for x:=1 to length(st2) do inc(count2[st2[x]]);
		
		for a:='a' to 'z' do if((count1[a]>0) and(count2[a]>0)) then 
		begin
			z:=count1[a];
			if z>count2[a] then z:=count2[a];
			for x:=1 to z do write(a);
		end;
		writeln;
	end;
end.