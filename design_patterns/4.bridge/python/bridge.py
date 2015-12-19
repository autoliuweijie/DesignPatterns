# coding: utf-8


class ContainerImp(object):
    ''' Implementor '''

    def add_at_position(self, char_in, position):
        pass

    def fetch_at_position(self, position):
        pass


class Array(ContainerImp):
    ''' ConcreteImplementorA '''

    def add_at_position(self, chat_in, position):
        print "Add char_in at postion to Array successfuly!\n"

    def fetch_at_position(self, position):
        print "Fetch at postion to Array successfuly!\n"


class Chain(ContainerImp):
    ''' ConcreteImplementorB '''

    def add_at_position(self, chat_in, position):
        print "Add char_in at postion to Array successfuly!\n"

    def fetch_at_position(self, position):
        print "Fetch at postion to Array successfuly!\n"


class Container(object):
    ''' Abstraction '''

    CONTAINER_IMP_LIST = {
        'Array': Array(),
        'Chain': Chain(),
    }

    def __init__(self, container_imp_in="Array"):
        self._container_imp = self.CONTAINER_IMP_LIST[container_imp_in]

    def add(self, char_in):
        pass

    def fetch(self):
        pass


class Stack(Container):
    ''' ConcreteAbstractionA '''

    def __init__(self, container_imp_in="Array"):
        super(Stack, self).__init__(container_imp_in)
        self._position = 0

    def add(self, char_in):
        self._container_imp.add_at_position(char_in, self._position)
        self._position += 1

    def fetch(self):
        self._container_imp.fetch_at_position(self._position)
        self._position -= 1


class Queue(Container):
    ''' ConcreteAbstractionB '''

    def __init__(self, container_imp_in="Array"):
        super(Queue, self).__init__(container_imp_in)
        self._position_head = 0
        self._position_tail = 0

    def add(self, char_in):
        self._position_head += 1
        self._container_imp.add_at_position(char_in, self._position_head)

    def fetch(self):
        self._container_imp.fetch_at_position(self._position_tail)
        self._position_tail -= 1


if __name__ == "__main__":
    new_stack = Stack(container_imp_in="Chain")
    new_stack.add('o')
    new_stack.fetch()
    new_queue = Queue(container_imp_in="Array")
    new_queue.add('o')
    new_queue.fetch()
