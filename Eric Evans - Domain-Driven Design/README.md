# Crunching Knowledge

- Bind model and implementation
- Cultivate a language based on the model
- Develop a knowledge-rich model with behavior and enforced rules
- Distill the model by dropping unneeded concepts
- Brainstorm and experiment with the model

It is the creativity of brainstorming and massive experimentation, leveraged through a model-based
language and disciplined by the feedback loop through implementation, that makes it possible to
find a knowledge-rich model and distill it.

# Communication and the Use of Language

## Ubiquitous language

- Shared language between domain experts and technical team, through all communication channels: code, speech, diagrams, documents
- Domain model terms, names of bounded contexts, terminology of large-scale structure and many pattern names should be part of it

## Documents and diagrams

- Vital detail about the design should be captured in the code
- The model is not the diagram. The diagram's purpose is to help communicate and explain the model
- Documents should complement code, be used in projects and stay current

# Binding model and implementation

## Model-driven design

Model and implementation should be binded:

> Model-driven design discords the dichotomy of analysis model and design to search out a single model that serves both purpose. [...] This requires us to be more demanding of the chosen model, since it must fulfill two quite different objectives

# Isolating the domain

Domain is generally a small part of a software application, but its importance is disproportionate to its size.

## Layered Architecture

- UI: Obtain user input
- Application: What to do and when to do it
- Domain: Business concepts, state and rules
- Infrastructure: How to do it

Domain objects should be free of displaying themselves, storing themselves and managing application tasks

# A model expressed in software

## Entities

Objects defined by a thread of continuity and identity
Two entities can have the same attributes, we still want to know which is which
Mutable

## Value objects

Objects defined by their attributes
Two values objects are interchangeable: it is not meaningful to care which is which
Immutable

## Services

An action or an operation that is not part of an entity or a value object

## Complexity

Avoid complexity and give deeper insight into the business of the domain through design cuts:

- Prefer value objects to entities
- Constrain the design to a traversal direction
- Reduce 1-to-many relationships when possible

# The Life Cycle of a Domain Object

Domains objects implementations need to:
> - Maintain integrity throughout the lifecycle
> - Preventing the model from getting swamped by the complexity of managing the lifecycle

## Aggregates

An Aggregate is a cluster of associated objects that we treat as a unit for the purpose of data changes.

Each Aggregate has:
- A root: a single, specific Entity contained in the Aggregate
- A boundary: what is inside the Aggregate

Objects outside of the Aggregate can hold the reference only to the root.

Invariants are consistency rules that must be maintained whenever data changes and will be enforced with the completion of each transaction.

## Factories

Encapsulate internal structure of a complex object when creating or reconstituting it.

When reconstituting a stored object, invariants violation should be handled gracefully: it shouldn't be ignored and it shouldn't be an error.

## Repositories

Access a subset of Aggregate roots through a search based on attributes

Repository should not handle transaction control: the client should have the context to initiate and commit units of work.