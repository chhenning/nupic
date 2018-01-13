from abc import ABCMeta
from abc import abstractmethod


from nupic.bindings.regions import PyRegion

class Serializable(object, metaclass=ABCMeta):

  @classmethod
  @abstractmethod
  def getSchema(cls):
    """
    Get Cap'n Proto schema.

    ..warning: This is an abstract method.  Per abc protocol, attempts to subclass
               without overriding will fail.

    @returns Cap'n Proto schema
    """
    pass


class AnomalyLikelihoodRegion(type(PyRegion), Serializable):

  def __init__(self,
               learningPeriod = 288,
               estimationSamples = 100,
               historicWindowSize = 8640,
               reestimationPeriod = 100):
    self.anomalyLikelihood = AnomalyLikelihood(
      learningPeriod = learningPeriod,
      estimationSamples = estimationSamples,
      historicWindowSize = historicWindowSize,
      reestimationPeriod = reestimationPeriod)
