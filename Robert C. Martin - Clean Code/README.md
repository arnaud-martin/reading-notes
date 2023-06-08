# Clean Code

## Why should one write clean code ?

- Teams working on a dirty codebase have a decreasing marginal productivity
- Software craftsmanship is what makes a developer professional

## What is clean code ?

- Code that looks like it was written by someone who cares
  - elegant, pleasing
  - reads well by humans with expressive names
  - makes the language look like it was written for the problem
  - what you expected
- Idea of "oneness"
  - focused : does one thing well
  - decisive : makes choices
  - minimal
  - reduced duplication
  - tiny abstractions
  - efficient : not tempted to badly optimize it
  - easy to change because tested

## Miscellaneous

- Code is read more that written
- Boy scout rule : leave the campground cleaner than you found it

# Meaningful names

## What is a meaningful name ?

A meaningful name explains why it exists, what it does and how it is used.

## Domain context

- Make context explicit to let others understand why the code does something
- Use business or company common knowledge
- Prefer wrapping variables with a Class than prefixing

## Technical context

- Make sure other developers understand what or how the code does something
- Use programming or computer science common knowledge

## Miscellaneous

- Class should be noun, methods should be verbs
- Avoid noise words like Object or Table and prefer types
- Use exactly one word per concept (not one for many or many for one)
- Use pronounceable words
- Use searchable words, prefer variables to magic numbers or strings

# Functions

- should be small
- should do things that are one level of abstraction below their name
- should read from higher to lower level of abstraction
- should do something or answer something : command/query separation
- should have no side effects
- are a way to avoid code duplication

## Arguments

- Functions should have none, one or two arguments
- Function and arguments should form a verb/noun pair
- No flag arguments
- Prefer Class to output argument : report.appendFooter() is better than appendFooter(report)

## Error handling

- Prefer exceptions to error codes
- Try catch is one thing so it should be a function

## Tests

- Nobody can write such code from the first time, so:
  - Write tests
  - Write draft code
  - Refactor

## Switch

A function that handles different cases, for example with a switch statement, can be a code smell. If other functions also act differently based on theses cases, one might need to refactor them to an abstract factory that create instances of the derivatives of a Class based on the switch statement cases. So that those functions can be dispatched polymorphically through the interface.

# Comments

- Express yourself in code rather than comments because they are not maintainable and go out of sync

## Exceptions: when comments can be insightful

- Explanation of intent: why did we do this ? why did we do it that way ?
- Warning of consequences when modifying or deleting
- TODO comments
- Amplification by redundancy
- Javadocs in public APIs

## Avoid

- Comments that could have been code
- Source control in comments rather than in git
- Non-local information
- Too much information: only give references to external resources

# Formatting

## Files

- Filename should indicate whether we are in the right module
- File content should read from top to bottom with highest level functions and algorithms first

## Vertical formatting

- Vertical openness between separate concepts
- Vertical density between related concepts
- Avoid forcing readers to hop around source files
- Caller function above the callee
- Variables close to usage, at top of file

## Horizontal formatting

- Horizontal alignment
- Indent
- Do not override linter... team rules

# Objects and data structures

There is an anti-symmetry between data and objects.

## Objects

- Hide data behind abstractions
- Expose functions operating on that data
- Object Oriented Programming
  - Easy to add news classes without changing existing functions
  - Hard to add new functions because all classes must change

## Data structures

- Expose data
- Have no meaningful functions
- Procedural programming
  - Easy to add new functions without changing the existing data structures
  - Hard to add new data structures because all the functions must change

## Hybrids

- Avoid hybrids

# Error handling

We are responsible for our code even when errors happen because of abnormal input or failing devices.
But error handling shouldn't obfuscate code.

## Exceptions

- Prefer exceptions to return codes: handling a return code can be forgotten by the callee and above all, calling code is cleaner with exceptions because error handling is separated from the happy path
- Write try-catch-finally first with tests about exceptions in a TDD-style to help maintain the transaction nature of the scope

## Exception design

- Prefer unchecked exceptions. Checked exceptions (written in the signature of the function) break open/closed principle and encapsulation: higher level functions know about lower-level functions implementation details
- Provide context with exceptions: strack trace is not sufficient to know the intent of the operation that failed
- Define exception classe in terms of a caller's need: how they are caught is the most important
- Wrap APIs to redefine exceptions, minimize dependencies on third party code or change its design

## Avoid

- Using exceptions when part of the normal flow: if you don't need to stop the execution of the flow, maybe you should use a special case pattern.
- Returning null: returning a special case object or throwing an exception is preferable
- Passing null: there is no good way to handle null in the callee function

# Boundaries

Good software design accomodate change without huge investments and rework. Change happens a lot at boundaries.

## Third-party code

- There is a natural tension between an interface's provider and its user: providers strive for broad applicability, users want it tailored to meet their needs
- Use learnings tests to conduct precise experiments about third-party code, separate learning from integration and assert that code stills works after version upgrades
- Write interfaces you wished you had, use the adapter pattern, only use what you need

# Unit tests

Tests are code so they need to be maintained. Therefore, they should have same standards of quality as their production code. Else, they will become a liability, then be disabled, and then refactoring the production code won't be possible.

## TDD

- Write a minimal failing unit test. Write minimal production code that passes it. Repeat

## Clean tests

- Arrange, act, assert
- Readibility: clarity, simplicity, density of expression
- Test-specific functions can help create a test-specific language
- Readibility is more important than performance for tests
- One test should test one concept, minimize the assertions

## F.I.R.S.T

- Fast: to execute them frequently
- Independent
- Repeatable: to run them in any environment
- Self-validating
- Timely: written before production code

# Classes

## Organization

- Public variables, static variables, private variables
- Public functions followed by private utilities

## Classes should be small

- Single Responsibility Principle: one reason to change
- High cohesion: instance variables should be used by most methods, if not all

## Dependency Inversion Principle

Classes should depend upon abstractions, not implementation details

# Systems

Separate start-up process from runtime logic by dependency injection

# Emergence

## Kent Beck's four rules of Simple Design

1. Run all the tests

- Only a testable system is verifiable and only a verifiable system should be deployed
- Writing tests encourages better design with low coupling and high cohesion

2. No duplication
3. Expressive
4. Minimal classes and methods

# Concurrency

Decoupling of what gets done from when it gets done:

- to improve application structure by separating concerns
- to improve performance when wait time can be shared between multiple threads

## Defense principles

- Separate concurrency-related code from other code to respect Single Responsibility Principle
- Partition data into independent subsets than can be operated on by independent threads

## Execution models

### Producer-Consumer

Bound resource is a queue.
Producers write in the queue when signaled by the consumer that there is free space.
Consumers read in the queue when signaled by the producer that there is work.

### Readers-Writers

A shared resource is often read fastly by readers and occasionnally updated slowly by writers.
Challenge is to find the balance between:

- throughput (letting readers read without being blocked)
- freshness of information (letting writers write the updated information)

### Dining Philosophers-

- A philosopher thinks when he is not hungry
- An hungry philosopher tries to pick up a fork from each side of his plate, eventually waiting until both are available.
- He puts them both back when he has eaten and starts thinking again

## Shutdown code is hard

## Testing threaded code

- Treat spurious system failures as candidate threading issues
- Make nonthreaded code work
- Make threaded code pluggable: vary number of threads, real or test doubles, speed, number of iterations
- Make threaded code tunable: allow changing while system is running, consider self-tuning based on throughput and system utilization
- Run with more threads than processors
- Run on different platforms
- Instrument your code to force failures (wait, sleep, yield, priority) by hand (but you have to find where to put it) or automatically with jiggling strategies (no results on Google)
