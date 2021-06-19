import ast
class Misc:

    def __init__(self):
        pass

    def get_keep_card_position(self, KCL, columns=3):
        """
        This method will be used to define the position for new widget.
        :param KCL: Keep_Card_List we will hold all the Cards.
        :return: tuple, it will return new position.
        """
        row = 0
        col = 0
        poslist = []
        # print("length of KCL: ", len(KCL))
        newest = None
        if len(KCL) > 0:
            for cp in range(len(KCL)):
                # print("length of cp: ",cp)
                cp += 1  # card position.
                # print("length of cp: ", cp)
                poslist.append((row, col))
                if cp % columns == 0:
                    row += 1
                    col = 0
                else:
                    col += 1

            newest = poslist[-1]
        return poslist, newest

    def get_children(self, parent=None):
        """
        This method will help us to retrieve all children present in a parent window. it will yield all child including nested child also.
        :param parent: window/Widget/Frame , it is the very first parent for which we want ot get children.
        :return: generator...
        """
        # this method will help us to get all the child present in the parent window
        for child in parent.winfo_children():
            yield child
            yield from self.get_children(child)


    def _eval(self, _str):
        """
        This method will convert our string into a python expression , keyword and values.
        :return: 
        """
        return ast.literal_eval(_str)