from .pipeline import Pipeline
from .naming_conventions import NamingConventionsAnalysis

class ConfigurablePipeline(Pipeline):
    def __init__(self, settings: dict = None):
        super().__init__()
        self.settings = settings or {}

    def passes(self) -> list[Pipeline]:
        passes = super().passes()

        config_passes = [
            ("naming_conventions", NamingConventionsAnalysis),
        ]

        for setting_key, pass_class in config_passes:
            if self.settings.get(setting_key, True):
                passes.append(pass_class())
        
        return passes