
Introduction
------------

This is a RegEx-to-DFA command line tool based on [http://augeas.net/libfa/ libfa].

 
Building
--------

To build the tool, run:

      cd src; make
      

Using
-----

Run:

      src/regextodfa <regularExpressionToCompile>
      
Example:

      src/regextodfa "(a|(bc)*|d)*e"


Explanation of the output
-------------------------

The output is a list of transitions and state acceptance information. A transition is of the form

      <fromStateNumber> <toStateNumber> <characterFrom> <characterTo>
      
All characters between "from" and "to" (ascii codes) shall be matched to the transition.

An accepting state information line is of the form

      :acc <stateNumber>
      
All states not listed as accepting are rejecting. The initial state is always state 0.

The tool returns an error code of 0 if the transition is successful, and 1 otherwise.


License
-------

RegEx-to-DFA is a repackaging of the [http://augeas.net Augeas] tool, which is released under the [Lesser General Public License, Version 2.1](http://www.gnu.org/licenses/lgpl-2.1.html)
This tool inherits that license. See the file COPYING for details.
