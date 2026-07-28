


Next: [lib\-gauge](lib_002dgauge.html), Previous: [lib\-fdbg](lib_002dfdbg.html), Up: [The Prolog Library](The-Prolog-Library.html)   \[[Contents](index.html#SEC_Contents "Table of contents")]\[[Index](Predicate-Index.html "Index")]





---


### 10\.15 Accessing Files And Directories—`library(file_systems)`




This module provides operations on files and directories, such as renaming,
deleting, opening, checking permissions, accessing members of.



The following principles have been observed:



* An absolute distinction is drawn between files and directories.
The set of operations
one can usefully perform on a directory is different from the set
one can perform on a file: for example, having
write permission to a directory allows the user to create new files in
it, not to rewrite the entire directory! If any routine in this package
tells you that a “file” exists, you can be sure that it means a
file and not a directory (and vice versa for “directory” exists).
* The directory scanning routines do not actually open the files they
find. Thus finer discriminations, such as that between
source and object code, are not made.
* All paths are expanded as if by `absolute_file_name/3`.
* Every predicate acts like a genuine logical relation insofar as it
possibly can.
* If anything goes wrong, the 
predicates
raise an error exception. Any time that a predicate
fails quietly, it should mean “this question is meaningful, but the
answer is no”.
* The directory scanning routines insist that the directory argument
name a searchable directory.
* On Unix\-like systems, symbolic links are followed by default and
symbolic links that can not be followed are treated as
non\-existing. This means `file_exists/1` will fail if passed
such a “broken” link and that neither
`file_members_of_directory/1` nor
`directory_members_of_directory/1` et al. will return such
a link.

On Windows, symbolic links (and other reparse points) are
*not* followed when enumerating directory contents with
`file_members_of_directory/1` nor
`directory_members_of_directory/1` et al. and are not
returned for these predicates.



The behavior for symbolic links (and reparse points) may change on
all platforms in the future to ensure a well defined and
consistent behavior on all platforms.



To see *all* members of a directory you can use
`absolute_file_name/3` with a `glob('*')` option.


The “property” routines use the same simplistic access control
model as that used by the `absolute_file_name/3`
`access/1`\-option. See [mpg\-ref\-absolute\_file\_name](mpg_002dref_002dabsolute_005ffile_005fname.html), for details.



Exported predicates:




`rename_file(+OldName, +NewName)`



OldName must identify an existing file, which will
be renamed to NewName. The details of just when this can be
done are operating\-system dependent.
Typically it is only possible to rename within the same file system.



`rename_directory(+OldName, +NewName)`



OldName must identify an existing directory, which will
be renamed to NewName. The details of just when this can be
done are operating\-system dependent.
Typically it is only possible to rename empty directories within
the same file system.



`delete_file(+OldName)`



OldName must identify an existing file, which will be deleted.



`delete_directory(+Directory)`
`delete_directory(+Directory, +Options)`



Directory 
must identify an existing directory, which will be deleted, if empty.
Options should be a list of at most one term of the form:



`if_nonempty(Value)`

Defines what to do if the directory is nonempty. One of:



`ignore`

The predicate simply succeeds, deleting nothing.



`fail`

The predicate simply fails, deleting nothing.



`error`

The predicate raises a permissison error.



`delete`

The predicate recursively deletes the directory and its contents.







`directory_exists(+Directory)`
`directory_exists(+Directory, +Mode)`





is true when Directory is an existing directory that is accessible
according to Mode. Mode defaults to `exist`.



This is more or less equivalent to
`absolute_file_name(File, _, [file_type(directory),access([exist|Mode]),file_errors(fail)])`.



`make_directory(+Directory)`



Directory is expanded, as if by `absolute_file_name/3`,
and the resulting directory is created.



`file_exists(+File)`
`file_exists(+File, +Mode)`





is true when File is an existing file that is accessible
according to Mode. Mode defaults to `exist`.



This is more or less equivalent to
`absolute_file_name(File, _, [access([exist|Mode]),file_errors(fail)])`.



`file_must_exist(+File)`
`file_must_exist(+File, +Mode)`





is like `file_exists(File[, Mode])` except that if the file is *not*
accessible it reports an error.



This is more or less equivalent to
`absolute_file_name(File, _, [access([exist|Mode]),file_errors(error)])`.



`directory_must_exist(+File)`
`directory_must_exist(+File, +Mode)`





is like `file_must_exists(File[, Mode])`, but for directories.



This is more or less equivalent to
`absolute_file_name(File, _, [file_type(directory),access([exists|Mode]),file_errors(error)])`.



`close_all_streams`



closes all the streams (other than the standard streams)
which are currently open. The time to call this is after
an `abort/0`. Note that `current_stream/3` does not notice the standard
streams.



`directory_member_of_directory(?BaseName, ?FullName)`



is true when BaseName is the name of a subdirectory of the current
directory (other than ’.’ or ’..’) and FullName is its absolute name.



This uses `absolute_file_name/3` with the `glob/1` option.



`directory_member_of_directory(+Directory, ?BaseName, ?FullName)`



is true when Directory is a name (not necessarily the absolute name)
of a directory, BaseName is the name of a subdirectory of that
directory (other than ’.’ or ’..’) and FullName is its absolute name.



This uses `absolute_file_name/3` with the `glob/1` option.



`directory_member_of_directory(+Directory, +Pattern, ?BaseName, ?FullName)`



is true when Directory is a name (not necessarily the absolute name)
of a directory, BaseName is the name of a directory of that
directory (other than ’.’ or ’..’) which matches the given Pattern,
and FullName is the absolute name of the subdirectory.



This uses `absolute_file_name/3` with a `glob(Pattern)` option.



`directory_members_of_directory(-Set)`



is true when Set is a set of BaseName\-FullName pairs being the
relative and absolute names of subdirectories of the current directory.



This uses `absolute_file_name/3` with the `glob/1` option.



`directory_members_of_directory(+Directory, -Set)`
is true when Set is a set of BaseName\-FullName pairs being the
relative and absolute names of subdirectories of the given Directory.
Directory need not be absolute; the FullNames will be regardless.



This uses `absolute_file_name/3` with the `glob/1` option.



`directory_members_of_directory(+Directory, +Pattern, -Set)`
is true when Set is a set of BaseName\-FullName pairs being the
relative and absolute names of subdirectories of the given Directory,
such that each BaseName matches the given Pattern.



This uses `absolute_file_name/3` with a `glob(Pattern)` option.



`file_member_of_directory(?BaseName, ?FullName)`



is true when BaseName is the name of a file in the current
directory and FullName is its absolute name.



This uses `absolute_file_name/3` with the `glob/1` option.



`file_member_of_directory(+Directory, ?BaseName, ?FullName)`
is true when Directory is a name (not necessarily the absolute name)
of a directory, BaseName is the name of a file in that directory,
and FullName is its absolute name.



This uses `absolute_file_name/3` with the `glob/1` option.



`file_member_of_directory(+Directory, +Pattern, ?BaseName, ?FullName)`
is true when Directory is a name (not necessarily the absolute name)
of a directory, BaseName is the name of a file in that directory
which matches the given Pattern,
and FullName is its absolute name.



This uses `absolute_file_name/3` with a `glob(Pattern)` option.



`file_members_of_directory(-Set)`



is true when Set is a set of BaseName\-FullName pairs being the
relative and absolute names of the files in the current directory.



This uses `absolute_file_name/3` with the `glob/1` option.



`file_members_of_directory(+Directory, -Set)`
is true when Set is a set of BaseName\-FullName pairs being the
relative and absolute names of the files in the given Directory.
Directory need not be absolute; the FullNames will be regardless.



This uses `absolute_file_name/3` with the `glob/1` option.



`file_members_of_directory(+Directory, +Pattern, -Set)`
is true when Set is a set of BaseName\-FullName pairs being the
relative and absolute names of subdirectories of the given Directory,
such that each BaseName matches the given Pattern.



This uses `absolute_file_name/3` with a `glob(Pattern)` option.



`directory_property(+Directory, ?Property)`



is true when Directory is a name of a directory, and Property is
a boolean property which that directory possesses, e.g.




```
    directory_property(., searchable).

```

The current set of file and directory properties include:



`readable`
`writable`
`executable`
`searchable`

Tries to determine whether the process has permission to read, write,
execute (only for files) or search (only for directories) the
file.




`size_in_bytes`
The size, in bytes, of the file. Not available for directories.




`create_timestamp`
`modify_timestamp`
`access_timestamp`

The time of creation, last modification or last access expressed as a
timestamp.




A *timestamp* is an integer expressing the time interval, in
seconds, since the “Epoch”. The *Epoch* is
the time zero hours, zero minutes, zero seconds, on January 1, 1970
Coordinated Universal Time (UTC).



The timestamp is what should be used when comparing information
between files since it is independent of locale issues like time zone and daylight
savings time etc.




`create_localtime`
`modify_localtime`
`access_localtime`

The same as the corresponding `…_timestamp` values passed
through `system:datime/2`, i.e. expressed as local time and
split up in the components year, month, day, hour, minute, seconds.




`set_user_id`
`set_group_id`
`save_text`

True if the set\-uid, set\-group\-id, save\-text bits, respectively, are
set for the file. Always false on Windows.




`who_can_read`
`who_can_write`
`who_can_execute`
`who_can_search`

A list containing the subset of `[user,group,other]` for the
process classes that can, respectively, read, write, execute (only for
files) or search (only for directories.




`owner_user_id`
`owner_group_id`

The id of the owner and group of the file. The id is an integer on
UNIX and an atom (expressed as a string security identifier) on
Windows.




`owner_user_name`
`owner_group_group`

The atom containing the name of the files owner and group respectively. On Windows a name
like `'DOMAIN\NAME'` will be used.



If for some reason the name cannot be found it will fall back to using
the same value as `owner_user_id` and `owner_group_id`.





Other properties may be added in the future. You can backtrack through
the available properties by calling `file_property/3` or
`directory_property/3` with an uninstantiated Property
argument.




`directory_property(+Directory, ?Property, ?Value)`
is true when Directory is a name of a directory, Property is a
property of directories, and Value is Directory’s Property Value.
See `directory_property/2`, above, for a list of properties.



`file_property(+File, ?Property)`



is true when File is a name of a file, and Property is
a boolean property which that file possesses, e.g.




```
    file_property('foo.txt', readable).

```

See `directory_property/2`, above, for a list of properties.



`file_property(+File, ?Property, ?Value)`
is true when File is a name of a file, Property is a
property of files, and Value is File’s Property Value.
See `directory_property/2`, above, for a list of properties.



`current_directory(-Directory)`
`current_directory(-Directory, +NewDirectory)`



Directory is unified with the current working directory and
the working directory is set to NewDirectory.






---



[|  |
| --- |](https://sicstus.sics.se/)


* [User's Manual](index.html#Top)


---

* [Table of Contents](index.html#TOC)* [Next](lib_002dgauge.html)* [Previous](lib_002dfdbg.html)* [Up](The-Prolog-Library.html)





---


[Send feedback on this subject.](mailto:sicstus-support@ri.se?subject=Documentation%20feedback%20on%20html/sicstus/lib_002dfile_005fsystems.html&body=Feedback%20on%20documentation%20node%20html/sicstus/lib_002dfile_005fsystems.html%20in%20User's%20Manual.)
