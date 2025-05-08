import XCTest
import SwiftTreeSitter
import TreeSitterPldoc

final class TreeSitterPldocTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_pldoc())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading pldoc grammar")
    }
}
