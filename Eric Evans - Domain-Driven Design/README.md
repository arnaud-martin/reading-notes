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
