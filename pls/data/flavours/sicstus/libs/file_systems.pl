:- module(file_systems,[directory_members_of_directory/3, file_members_of_directory/2, directory_member_of_directory/4,
 file_member_of_directory/4, directory_property/2, directory_must_exist/1,
 file_must_exist/2, directory_member_of_directory/2, directory_exists/1,
 directory_members_of_directory/1, directory_member_of_directory/3, file_exists/1,
 file_member_of_directory/3, file_member_of_directory/2, close_all_streams/0,
 file_members_of_directory/1, file_must_exist/1, file_property/2,
 delete_directory/2, file_members_of_directory/3, directory_property/3,
 file_property/3, file_exists/2, make_directory/1,
 rename_directory/2, rename_file/2, directory_exists/2,
 current_directory/2, current_directory/1, delete_file/1,
 directory_members_of_directory/2, delete_directory/1, directory_must_exist/2]).
 

%! rename_file(+OldName, +NewName)
%
% OldName must identify an existing file, which will be renamed to NewName.
% The details of just when this can be done are operating-system dependent.
% Typically it is only possible to rename within the same file system.
%
% @param OldName *atom*
% @param NewName *atom*

%! rename_directory(+OldName, +NewName)
%
% OldName must identify an existing directory, which will be renamed to NewName.
% The details of just when this can be done are operating-system dependent.
% Typically it is only possible to rename empty directories within the same file system.
%
% @param OldName *atom*
% @param NewName *atom*

%! delete_file(+OldName)
%
% OldName must identify an existing file, which will be deleted.
%
% @param OldName *atom*

%! delete_directory(+Directory)
%! delete_directory(+Directory, +Options)
%
% Directory must identify an existing directory, which will be deleted, if empty.
% Options should be a list of at most one term of the form:
%
% `if_nonempty(Value)`
% Defines what to do if the directory is nonempty. One of:
%
% `ignore`
% The predicate simply succeeds, deleting nothing.
%
% `fail`
% The predicate simply fails, deleting nothing.
%
% `error`
% The predicate raises a permission error.
%
% `delete`
% The predicate recursively deletes the directory and its contents.
%
% @param Directory *atom*
% @param Options *list*

%! directory_exists(+Directory)
%! directory_exists(+Directory, +Mode)
%
% is true when Directory is an existing directory that is accessible according to Mode.
% Mode defaults to `exist`.
% This is more or less equivalent to
% `absolute_file_name(File, _, [file_type(directory),access([exist|Mode]),file_errors(fail)])`.
%
% @param Directory *atom*
% @param Mode *atom*

%! make_directory(+Directory)
%
% Directory is expanded, as if by `absolute_file_name/3`,
% and the resulting directory is created.
%
% @param Directory *atom*

%! file_exists(+File)
%! file_exists(+File, +Mode)
%
% is true when File is an existing file that is accessible according to Mode.
% Mode defaults to `exist`.
% This is more or less equivalent to
% `absolute_file_name(File, _, [access([exist|Mode]),file_errors(fail)])`.
%
% @param File *atom*
% @param Mode *atom*

%! file_must_exist(+File)
%! file_must_exist(+File, +Mode)
%
% is like `file_exists(File[, Mode])` except that if the file is *not*
% accessible it reports an error.
% This is more or less equivalent to
% `absolute_file_name(File, _, [access([exist|Mode]),file_errors(error)])`.
%
% @param File *atom*
% @param Mode *atom*

%! directory_must_exist(+Directory)
%! directory_must_exist(+Directory, +Mode)
%
% is like `file_must_exists(File[, Mode])`, but for directories.
% This is more or less equivalent to
% `absolute_file_name(File, _, [file_type(directory),access([exists|Mode]),file_errors(error)])`.
%
% @param Directory *atom*
% @param Mode *atom*

%! close_all_streams
%
% closes all the streams (other than the standard streams)
% which are currently open. The time to call this is after
% an `abort/0`. Note that `current_stream/3` does not notice the standard
% streams.

%! directory_member_of_directory(?BaseName, ?FullName)
%
% is true when BaseName is the name of a subdirectory of the current
% directory (other than '.' or '..') and FullName is its absolute name.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param BaseName *atom*
% @param FullName *atom*

%! directory_member_of_directory(+Directory, ?BaseName, ?FullName)
%
% is true when Directory is a name (not necessarily the absolute name)
% of a directory, BaseName is the name of a subdirectory of that
% directory (other than '.' or '..') and FullName is its absolute name.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param Directory *atom*
% @param BaseName *atom*
% @param FullName *atom*

%! directory_member_of_directory(+Directory, +Pattern, ?BaseName, ?FullName)
%
% is true when Directory is a name (not necessarily the absolute name)
% of a directory, BaseName is the name of a directory of that
% directory (other than '.' or '..') which matches the given Pattern,
% and FullName is the absolute name of the subdirectory.
% This uses `absolute_file_name/3` with a `glob(Pattern)` option.
%
% @param Directory *atom*
% @param Pattern *atom*
% @param BaseName *atom*
% @param FullName *atom*

%! directory_members_of_directory(-Set)
%
% is true when Set is a set of BaseName-FullName pairs being the
% relative and absolute names of subdirectories of the current directory.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param Set *list of pair* a list of `BaseName-FullName` pairs.

%! directory_members_of_directory(+Directory, -Set)
%
% is true when Set is a set of BaseName-FullName pairs being the
% relative and absolute names of subdirectories of the given Directory.
% Directory need not be absolute; the FullNames will be regardless.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param Directory *atom*
% @param Set *list of pair* a list of `BaseName-FullName` pairs.

%! directory_members_of_directory(+Directory, +Pattern, -Set)
%
% is true when Set is a set of BaseName-FullName pairs being the
% relative and absolute names of subdirectories of the given Directory,
% such that each BaseName matches the given Pattern.
% This uses `absolute_file_name/3` with a `glob(Pattern)` option.
%
% @param Directory *atom*
% @param Pattern *atom*
% @param Set *list of pair* a list of `BaseName-FullName` pairs.

%! file_member_of_directory(?BaseName, ?FullName)
%
% is true when BaseName is the name of a file in the current
% directory and FullName is its absolute name.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param BaseName *atom*
% @param FullName *atom*

%! file_member_of_directory(+Directory, ?BaseName, ?FullName)
%
% is true when Directory is a name (not necessarily the absolute name)
% of a directory, BaseName is the name of a file in that directory,
% and FullName is its absolute name.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param Directory *atom*
% @param BaseName *atom*
% @param FullName *atom*

%! file_member_of_directory(+Directory, +Pattern, ?BaseName, ?FullName)
%
% is true when Directory is a name (not necessarily the absolute name)
% of a directory, BaseName is the name of a file in that directory
% which matches the given Pattern,
% and FullName is its absolute name.
% This uses `absolute_file_name/3` with a `glob(Pattern)` option.
%
% @param Directory *atom*
% @param Pattern *atom*
% @param BaseName *atom*
% @param FullName *atom*

%! file_members_of_directory(-Set)
%
% is true when Set is a set of BaseName-FullName pairs being the
% relative and absolute names of the files in the current directory.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param Set *list of pair* a list of `BaseName-FullName` pairs.

%! file_members_of_directory(+Directory, -Set)
%
% is true when Set is a set of BaseName-FullName pairs being the
% relative and absolute names of the files in the given Directory.
% Directory need not be absolute; the FullNames will be regardless.
% This uses `absolute_file_name/3` with the `glob/1` option.
%
% @param Directory *atom*
% @param Set *list of pair* a list of `BaseName-FullName` pairs.

%! file_members_of_directory(+Directory, +Pattern, -Set)
%
% is true when Set is a set of BaseName-FullName pairs being the
% relative and absolute names of subdirectories of the given Directory,
% such that each BaseName matches the given Pattern.
% This uses `absolute_file_name/3` with a `glob(Pattern)` option.
%
% @param Directory *atom*
% @param Pattern *atom*
% @param Set *list of pair* a list of `BaseName-FullName` pairs.

%! directory_property(+Directory, ?Property)
%
% is true when Directory is a name of a directory, and Property is
% a boolean property which that directory possesses, e.g.
%
% ```
%     directory_property(., searchable).
% ```
%
% The current set of file and directory properties include:
%
% `readable`
% `writable`
% `executable`
% `searchable`
% Tries to determine whether the process has permission to read, write,
% execute (only for files) or search (only for directories) the file.
%
% `size_in_bytes`
% The size, in bytes, of the file. Not available for directories.
%
% `create_timestamp`
% `modify_timestamp`
% `access_timestamp`
% The time of creation, last modification or last access expressed as a
% timestamp. A *timestamp* is an integer expressing the time interval, in
% seconds, since the "Epoch". The *Epoch* is
% the time zero hours, zero minutes, zero seconds, on January 1, 1970
% Coordinated Universal Time (UTC).
% The timestamp is what should be used when comparing information
% between files since it is independent of locale issues like time zone and daylight
% savings time etc.
%
% `create_localtime`
% `modify_localtime`
% `access_localtime`
% The same as the corresponding `..._timestamp` values passed
% through `system:datime/2`, i.e. expressed as local time and
% split up in the components year, month, day, hour, minute, seconds.
%
% `set_user_id`
% `set_group_id`
% `save_text`
% True if the set-uid, set-group-id, save-text bits, respectively, are
% set for the file. Always false on Windows.
%
% `who_can_read`
% `who_can_write`
% `who_can_execute`
% `who_can_search`
% A list containing the subset of `[user,group,other]` for the
% process classes that can, respectively, read, write, execute (only for
% files) or search (only for directories.
%
% `owner_user_id`
% `owner_group_id`
% The id of the owner and group of the file. The id is an integer on
% UNIX and an atom (expressed as a string security identifier) on
% Windows.
%
% `owner_user_name`
% `owner_group_group`
% The atom containing the name of the files owner and group respectively. On Windows a name
% like `'DOMAIN\NAME'` will be used.
% If for some reason the name cannot be found it will fall back to using
% the same value as `owner_user_id` and `owner_group_id`.
%
% Other properties may be added in the future. You can backtrack through
% the available properties by calling `file_property/3` or
% `directory_property/3` with an uninstantiated Property
% argument.
%
% @param Directory *atom*
% @param Property *atom*

%! directory_property(+Directory, ?Property, ?Value)
%
% is true when Directory is a name of a directory, Property is a
% property of directories, and Value is Directory's Property Value.
% See `directory_property/2`, above, for a list of properties.
%
% @param Directory *atom*
% @param Property *atom*
% @param Value *term*

%! file_property(+File, ?Property)
%
% is true when File is a name of a file, and Property is
% a boolean property which that file possesses, e.g.
%
% ```
%     file_property('foo.txt', readable).
% ```
%
% See `directory_property/2`, above, for a list of properties.
%
% @param File *atom*
% @param Property *atom*

%! file_property(+File, ?Property, ?Value)
%
% is true when File is a name of a file, Property is a
% property of files, and Value is File's Property Value.
% See `directory_property/2`, above, for a list of properties.
%
% @param File *atom*
% @param Property *atom*
% @param Value *term*

%! current_directory(-Directory)
%! current_directory(-Directory, +NewDirectory)
%
% Directory is unified with the current working directory and
% the working directory is set to NewDirectory.
%
% @param Directory *atom*
% @param NewDirectory *atom*
