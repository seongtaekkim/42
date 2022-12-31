

/**
 *
	<command line>	::=  	<job>
						|	<job> '&'
						| 	<job> '&' <command line>


	<job>			::=		<command>
						|	< job > '|' < command >

	<command>		::=		<simple command>
						|	<simple command> '<' <filename>
						|	<simple command> '>' <filename>

	<simple command>::=		<pathname>
						|	<simple command>  <token>
 *
 *
 *
**/