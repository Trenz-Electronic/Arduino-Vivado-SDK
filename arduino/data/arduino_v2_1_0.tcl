#*****************************************************************************
# http://igg.me/at/zynq
#
#*****************************************************************************

proc generate {lib_handle} {
    puts "Run Arduino Library generate"

}

proc xgen_opts_file {libhandle} {

	# Open xparameters.h file
	set file_handle [xopen_include_file "xparameters.h"]

	close $file_handle

	puts "Copy Arduino header files"
	
	# Copy the include files to the include directory
	set srcdir [file join src include]
	set dstdir [file join .. .. include]

	# Create dstdir if it does not exist
	if { ! [file exists $dstdir] } {
		file mkdir $dstdir
	}

	# Get list of files in the srcdir
	set sources [glob -join $srcdir *.h]
	
	# Copy each of the files in the list to dstdir
	foreach source $sources {
		file copy -force $source $dstdir
	}
}

