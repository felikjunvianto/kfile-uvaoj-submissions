var n,p,list,max,x,y,z:longint;
	dummy:string;
	prop_name,temp:string;
	price,price_min:real;
	
begin
	z:=0;
	repeat
		readln(n,p);
		if n=0 then break;
		inc(z);
		for x:=1 to n do readln(dummy);
		
		max:=0;
		for x:=1 to p do
		begin
			readln(temp);
			readln(price,list);
			if x=1 then price_min:=price;
			for y:=1 to list do readln(dummy);
			if((list>max)or((list=max)and(price<price_min))) then
			begin
				max:=list;
				prop_name:=temp;
				price_min:=price;
			end;
		end;
		
		if z>1 then writeln;
		writeln('RFP #',z);
		writeln(prop_name);
	until(n=0);
end.