var n,m,x,i,j,y,satu,dua:longint;
	book:array[1..10000] of longint;
	
procedure sort(terkiri,terkanan:longint);
	var kiri,kanan,temp,pivot:longint;
	
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=book[(kiri+kanan) div 2];
			
			while kiri<=kanan do
			begin
				while book[kiri] <pivot do inc(kiri);
				while book[kanan] >pivot do dec(kanan);
				if kiri<= kanan then
				begin
					temp:=book[kiri];
					book[kiri]:=book[kanan];
					book[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			sort(terkiri,kanan);
			sort(kiri,terkanan);
		end;
	end;
	
begin
	while not(eof) do
	begin
		readln(n);
		fillchar(book,sizeof(book),0);
		for x:=1 to n do read(book[x]);
		readln;
		readln(m);
		readln;
		sort(1,n);
		y:=1000001;
		for i:=1 to n-1 do
			for j:=i+1 to n do
				if book[i]+book[j]>m then break else
					if book[i]+book[j]=m then
						if book[j]-book[i]<y then
							begin
								y:=book[j]-book[i];
								satu:=i;
								dua:=j;
							end;
		writeln('Peter should buy books whose prices are ',book[satu],' and ',book[dua],'.');
		writeln;
	end;
end.