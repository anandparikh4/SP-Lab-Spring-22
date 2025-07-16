#!/usr/bin/gawk -f

# PROVIDE EXECUTABLE PERMISSION AS : chmod +x 20CS10007_A2.awk
# RUN AS : ./20CS10007_A2.awk <accounts.txt>

function date(s,month){

split(s,_DATE,"-")
if(_DATE[2] == "01") _DATE[2] = "January"
if(_DATE[2] == "02") _DATE[2] = "February"
if(_DATE[2] == "03") _DATE[2] = "March"
if(_DATE[2] == "04") _DATE[2] = "April"
if(_DATE[2] == "05") _DATE[2] = "May"
if(_DATE[2] == "06") _DATE[2] = "June"
if(_DATE[2] == "07") _DATE[2] = "July"
if(_DATE[2] == "08") _DATE[2] = "August"
if(_DATE[2] == "09") _DATE[2] = "September"
if(_DATE[2] == "10") _DATE[2] = "October"
if(_DATE[2] == "11") _DATE[2] = "November"
if(_DATE[2] == "12") _DATE[2] = "December"

_DATE[1] = int(_DATE[1])
_DATE[3] = int(_DATE[3])     # convert day and year to integers and month to month name 


}

function is_leap(temp_date){
	year = temp_date[3]
	if(year%4 == 0) return int(1)
	return int(0)
}

function difference(_DATE,prev_DATE){         # finds the number of days between previous and current date

if(_DATE[2] == prev_DATE[2]){    # same month
	return _DATE[1] - prev_DATE[1]
}

# else previous month = current month-1 and the current date is aslo 1st of that month

if(prev_DATE[2] == "January" || prev_DATE[2] == "March" || prev_DATE[2] == "May" || prev_DATE[2] == "July" || prev_DATE[2] == "August" || prev_DATE[2] == "October" || prev_DATE[2] == "December"){
	return 31 - prev_DATE[1] + _DATE[1] 
}

if(prev_DATE[2] == "February"){
	if(is_leap(prev_DATE) == int(1)) return 29 - prev_DATE[1] + _DATE[1]
	else return 28 - prev_DATE[1] + _DATE[1]
}

return 30 - prev_DATE[1] + _DATE[1]

}

BEGIN{
	FS = ":"
	#print("My passbook")
	interest = 0
	new = int(0)
	last_balance = int(0)
}

{

date($1)        # always evaluate the date first

if($5 == "ACCOUNT OPENED"){   # set current balance to initial amount

	curr_balance = int($4)
	prev_DATE[1] = _DATE[1]
	prev_DATE[2] = _DATE[2]
	prev_DATE[3] = _DATE[3]

}  

if($5 == "INTEREST"){  # Simply copy this to the output, and go to next line, nothing to do here, since this is a line WE introduced
		next      # VERY IMPORTANT
}

n_days = difference(_DATE,prev_DATE)

if(_DATE[3] != prev_DATE[3]){   # year has changed, since months are consecutive it means prev_DATE[2] = December and _DATE[2] = January. Moreover it has to be 1st Jan as salary is added on this day

	if(is_leap(prev_DATE)==int(1)) interest += (31-prev_DATE[1]) * curr_balance * 5/36600
	else interest += (31-prev_DATE[1]) * curr_balance * 5/36500
	if (interest - int(interest)>=0.5) interest = int(interest)+1
	else interest = int(interest)
	print "+++ Interest of year " prev_DATE[3] " is " interest
	curr_balance += interest
	
	k++
	overwrite[k][1] = "31-12-"prev_DATE[3]
	overwrite[k][2] = interest
	overwrite[k][3] = ""
	overwrite[k][4] = curr_balance
	overwrite[k][5] = "INTEREST"

	interest = int(0)

}

else{
	if(is_leap(prev_DATE) == int(1)) interest += n_days * curr_balance * 5/36600
	else interest += n_days * curr_balance * 5/36500
}

if($4 == ""){        # if balance is empty, new transactions found
	new++
	text[new][1] = _DATE[1]
	text[new][2] = _DATE[2]
	text[new][3] = _DATE[3]
	if(last_balance == int(0)) last_balance = curr_balance
}

curr_balance += int($2)            # if the string is empty, we will automatically get 0
curr_balance -= int($3)

if($4 == ""){
	if($3 == ""){
		text[new][4] = "Credit"
		text[new][5] = $2
	}
	else{
		text[new][4] = "Debit"
		text[new][5] = $3
	}
	text[new][6] = $5
	text[new][7] = curr_balance
	
}

# finally update the previous date 
prev_DATE[1] = _DATE[1]
prev_DATE[2] = _DATE[2]
prev_DATE[3] = _DATE[3]
prev_balance = curr_balance
k++
overwrite[k][1] = $1
overwrite[k][2] = $2
overwrite[k][3] = $3
overwrite[k][4] = curr_balance
overwrite[k][5] = $5

}

END{
	if(new > 0){
		print "+++ New transactions found"
		print "Last balance = " last_balance
		for(i=1;i<=new;i++) print text[i][2] " " text[i][1] ", " text[i][3] " " text[i][4] " of " text[i][5] " for " text[i][6] " Balance = " text[i][7]
		
	}
	else print "+++ No new transactions found"
	if (interest - int(interest)>=0.5) interest = int(interest)+1
	else interest = int(interest)
	print "+++ Interest of this year (" _DATE[3] ") up to the last transaction = " interest
	
	print overwrite[1][1] ":" overwrite[1][2] ":" overwrite[1][3] ":" overwrite[1][4] ":" overwrite[1][5] > "accounts.txt"
	for(i=2;i<=k;i++){
		print overwrite[i][1] ":" overwrite[i][2] ":" overwrite[i][3] ":" overwrite[i][4] ":" overwrite[i][5] >> "accounts.txt" 
	} 
}
