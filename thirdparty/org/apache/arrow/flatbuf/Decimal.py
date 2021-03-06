# automatically generated by the FlatBuffers compiler, do not modify

# namespace: flatbuf

import flatbuffers

class Decimal(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsDecimal(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Decimal()
        x.Init(buf, n + offset)
        return x

    # Decimal
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Decimal
    def Precision(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Decimal
    def Scale(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

def DecimalStart(builder): builder.StartObject(2)
def DecimalAddPrecision(builder, precision): builder.PrependInt32Slot(0, precision, 0)
def DecimalAddScale(builder, scale): builder.PrependInt32Slot(1, scale, 0)
def DecimalEnd(builder): return builder.EndObject()
